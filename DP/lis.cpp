//
// Created by seyed on 5/20/2024.
//
using namespace std;
vector<int> LIS(vector<int> arr){
    int ma[arr.size()+2],before[arr.size()+2];
    int maxNum=0,maxIndex=0;
    vector<int> ans;
    for (int i = 0; i < arr.size(); ++i) {
        int maximum = 0,index;
        before[i]=-1;
        ma[i]=1;
        for (int j = 0; j < i; ++j) {
            if(arr[i] >= arr[j] && ma[j]+1>maximum){
                maximum = ma[j]+1;
                index=j;
            }
        }
        ma[i]=maximum;
        before[i]=index;
        if(ma[i]>maxNum){
            maxNum=ma[i];
            maxIndex=i;
        }
    }
    while(maxIndex){
        ans.push_back(arr[maxIndex]);
        maxIndex = before[maxIndex];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int mainLIS() {
    // Example array
    vector<int> arr = {10, 22, 9, 33, 21, 5, 41, 60};

    // Calling the LIS function
    vector<int> lisResult = LIS(arr);

    // Printing the result
    cout << "Longest Increasing Subsequence: ";
    for(int num : lisResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}