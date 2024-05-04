//
// Created by seyed on 5/4/2024.
//
using namespace std;
vector<pair<int,pair<int,int>>> prime(int** l,int n,int max){
    vector<pair<int,pair<int,int>>> ans;
    int mindist[n],nearest[n];
    for (int i = 1; i < n; ++i) {
        nearest[i]=0;
        mindist[i]=l[0][i];
    }
    for (int i = 0; i < n-1; ++i) {
        int min=max,c=0;
        for (int j = 1; j < n; ++j) {
            if(mindist[j]>0 && mindist[j]<min){
                min = mindist[j];
                c = j;
            }
        }
        ans.emplace_back(mindist[c], make_pair(nearest[c],c));
        mindist[c]=-1;
        for (int j = 1; j < n; ++j) {
            if(mindist[j]>0 && mindist[j]>l[c][j]){
                mindist[j] = l[c][j];
                nearest[j]=c;
            }
        }
    }
    return ans;
}
void mainPrime(){

    int n = 5;
    int max = 7;
    int** l = new int*[n];
    for (int i = 0; i < n; ++i) {
        l[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            l[i][j] = 10000000;
        }
    }

    l[0][1] = 1;
    l[0][2] = 5;
    l[1][2] = 3;
    l[1][3] = 4;
    l[2][3] = 5;
    l[2][4] = 7;
    l[3][4] = 5;

    vector<pair<int,pair<int,int>>> result = prime(l, n, max);

    for (const auto& edge : result) {
        std::cout << "Distance: " << edge.first << ", Nearest: " << edge.second.first << ", Current: " << edge.second.second << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] l[i];
    }
    delete[] l;

}