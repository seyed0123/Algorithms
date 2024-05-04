//
// Created by seyed on 5/4/2024.
//
#include "../DS/disjointSet.cpp"
using namespace std;

vector<pair<int,pair<int,int>>> kruskal(vector<int>v,vector<pair<int,pair<int,int>>>e){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> heap;
    for (auto edge:e) {
        heap.push(edge);
    }
    DisjointSet set(v.size());
    vector<pair<int,pair<int,int>>> res;
    while (res.size()<v.size()-1){
        auto x=heap.top();
        heap.pop();
        if(set.find(x.second.first) !=set.find(x.second.second)){
            res.push_back(x);
            set.merge(x.second.second,x.second.first);
        }
    }
    return res;

}
int mainKruskal(){
    vector<int> vertices = {0, 1, 2, 3, 4};

    vector<pair<int, pair<int, int>>> edges = {
            {1, {0, 1}},
            {3, {0, 2}},
            {5, {0, 3}},
            {2, {1, 2}},
            {3, {1, 3}},
            {9, {2, 3}},
            {1, {2, 4}},
            {4, {3, 4}}
    };

    vector<pair<int, pair<int, int>>> mst = kruskal(vertices, edges);

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << "Edge: (" << edge.second.first << ", " << edge.second.second << ") with weight: " << edge.first << endl;
    }

    return 0;
}