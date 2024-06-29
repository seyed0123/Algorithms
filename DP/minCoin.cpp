//
// Created by seyed on 5/13/2024.
//
using namespace std;
vector<int> MinCoin (vector<int>coins , int amount){
    int arr[coins.size()][amount];
    bool flag[coins.size()][amount];
    vector <int> ret;
    for (int i = 0; i < amount; ++i) {
        if(i>coins[0]){
            arr[1][i]=0;
            flag[1][i]=true;
        }else{
            arr[1][i]=i/coins[0];
            flag[1][i]=true;
        }
    }
    for (int i = 0; i < coins.size(); ++i) {
        arr[0][i]=0;
        flag[0][i]=false;
    }
    for (int i = 2; i < coins.size(); ++i) {
        for (int j = 1; j < amount; ++j) {
            if ( j > coins[i]){
                arr[j][i]=arr[j][i-1];
            }else{
                arr[j][i]=min(arr[j][i-1],1+arr[j-coins[i]][i]);
            }
        }
    }
    return ret;
}
