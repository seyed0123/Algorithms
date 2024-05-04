//
// Created by seyed on 5/4/2024.
//
class DisjointSet{
    int*rank,*parent,n;
public:
    DisjointSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n=n;
        for (int i = 0; i < n; ++i) {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(parent[x]==x)
            return x;
        else
            return find(parent[x]);
    }
    void merge(int l,int p){
        int x = find(l),y=find(p);
        if(rank[x]>rank[y])
            parent[y]=x;
        else if(rank[x]<rank[y])
            parent[x]=y;
        else{
            parent[x]=y;
            rank[y]++;
        }
    }
};
int mainDisjointSet()
{

    // Function Call
    DisjointSet obj(5);
    obj.merge(0, 2);
    obj.merge(4, 2);
    obj.merge(3, 1);

    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}