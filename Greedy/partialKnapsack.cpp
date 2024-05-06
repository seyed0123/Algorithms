//
// Created by seyed on 5/6/2024.
//
using namespace std;
vector<pair<int,int>> PartialKnapsack(vector<pair<int,int>> items,int w){
    vector<pair<double,pair<int,int>>> arr;
    vector<pair<int,int>> ret;
    for(auto item:items){
        arr.emplace_back(item.first/double(item.second), make_pair(item.first,item.second));
    }
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-1,j=0;j<w && i>=0 ;i--){
        if(arr[i].second.second + j < w)
        {
            j+=arr[i].second.second;
            ret.push_back(arr[i].second);
        }else{
            ret.emplace_back(arr[i].first*(w-j),(w-j));
            j=w;
        }
    }
    return ret;
}
int mainPartialKnapsack() {
    vector<pair<int,int>> items = {
            {10, 60},
            {20, 100},
            {25, 70},
            {40, 150},
            {10, 10},
            {30, 120}
    };

    int w = 150;

    vector<pair<int,int>> result = PartialKnapsack(items, w);
    cout << "Items included in the knapsack:" << endl;
    for(const auto& item : result) {
        cout << "Weight: " << item.second << ", Value: " << item.first << endl;
    }

    return 0;
}