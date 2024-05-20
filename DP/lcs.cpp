//
// Created by seyed on 5/20/2024.
//
using namespace std;
vector<int> LCS(vector<int> s1,vector<int>s2){
    int t[s1.size()+2][s2.size()+2],d[s1.size()+2][s2.size()+2];
    vector<int> ans;

    for (int i = 0; i <= s1.size(); ++i) {
        t[i][0]=0;
    }
    for (int i = 0; i <= s2.size(); ++i) {
        t[0][i]=0;
    }

    for (int i = 1; i <= s1.size() ; ++i) {
        for (int j = 1; j <= s2.size() ; ++j) {
            t[i][j]=-1;
            if(s1[i-1]==s2[j-1]){
                t[i][j]=t[i-1][j-1]+1;
                d[i][j]=2;
            }if(t[i][j-1]>t[i][j]){
                t[i][j]=t[i][j-1];
                d[i][j]=1;
            }if(t[i-1][j]>t[i][j]){
                t[i][j]=t[i-1][j];
                d[i][j]=0;
            }
        }
    }
    int x=s1.size(),y=s2.size();
    while(true){
        if(x==0 || y==0)
            break;
        if(d[x][y]==2){
            ans.push_back(s1[x-1]);
            x--;
            y--;
        }else if(d[x][y]==0){
            x--;
        }else{
            y--;
        }
    }
    return ans;
}

int mainLCS() {
    // Example sequences
    vector<int> s1 = {1, 2, 3, 4, 5, 9, 0};
    vector<int> s2 = {3, 1, 5, 2, 7};

    // Calling the LCS function
    vector<int> lcsResult = LCS(s1, s2);

    // Printing the result
    cout << "Longest Common Subsequence: ";
    for(int num : lcsResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}