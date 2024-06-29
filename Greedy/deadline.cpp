//
// Created by seyed on 5/6/2024.
//
using namespace std;

vector<pair<int,int>> Deadlines(vector<pair<int,int>> works,int ma){
    sort(works.begin(),works.end());
    int m = min(ma,int(works.size()));
    pair<int,int> jobs[m];
    for (int i = 1; i <= m; ++i) {
        jobs[i]= make_pair(0,0);
    }
    DisjointSet set(m+1);
    vector<pair<int,int>> ret;
    for(int i=works.size()-1;i>=0;i--){
        int f = set.find(works[i].second);
        if(!f){
            continue;
        }
        jobs[f]=works[i];
        set.merge(f,f-1);
    }
    for (int i = 1; i <= m; ++i) {
        if(jobs[i]!= make_pair(0,0)){
            ret.push_back(jobs[i]);
        }
    }
    return ret;
}
int mainDeadline() {

    vector<pair<int,int>> works = {
            {1, 3},
            {6, 2},
            {3, 2},
            {5, 4},
            {5, 3}
    };
    int ma = 6;
    vector<pair<int,int>> result = Deadlines(works, ma);
    cout << "Jobs scheduled:" << endl;
    for(const auto& job : result) {
        cout << "Value: " << job.first << ", Deadline: " << job.second << endl;
    }

    return 0;
}