//
// Created by seyed on 5/4/2024.
//
using namespace std;
vector<pair<int,pair<int,int>>> digkstra(int** l,int n,int max,int source){
    vector<pair<int,pair<int,int>>> ans;
    int mindist[n],nearest[n];
    bool check[n];
    for (int i = 0; i < n; ++i) {
        nearest[i]=0;
        mindist[i]=l[source][i];
        check[i]=false;
    }
    mindist[source] = 0;
    check[source] =true;
    for (int i = 0; i < n-1; ++i) {
        int min=max,c=0;
        for (int j = 0; j < n; ++j) {
            if(!check[j] && mindist[j]<min){
                min = mindist[j];
                c = j;
            }
        }
        ans.emplace_back(mindist[c], make_pair(nearest[c],c));
        check[c]=true;
        for (int j = 0; j < n; ++j) {
            if(!check[j] && mindist[j] > l[c][j]+mindist[c]){
                mindist[j] = l[c][j]+mindist[c];
                nearest[j]=c;
            }
        }
    }
    return ans;
}
void mainDigstra(){

    int n = 5;
    int max = 10000000;
    int** l = new int*[n];
    for (int i = 0; i < n; ++i) {
        l[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            l[i][j] = max;
        }
    }

    l[0][1] = 1;
    l[0][2] = 5;
    l[1][2] = 3;
    l[1][3] = 4;
    l[2][3] = 5;
    l[2][4] = 7;
    l[3][4] = 5;

    vector<pair<int,pair<int,int>>> result = digkstra(l, n, max,2);

    for (const auto& edge : result) {
        std::cout << "Distance: " << edge.first << ", Nearest: " << edge.second.first << ", Current: " << edge.second.second << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] l[i];
    }
    delete[] l;

}