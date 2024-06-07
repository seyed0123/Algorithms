//
// Created by seyed on 6/7/2024.
//
using namespace std;

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}


int** Floyd(int **matrix,int n){
    int **p = new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i]= new int[n];
        for (int j = 0; j < n; ++j) {
            p[i][j] = i;
        }
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j]>matrix[i][k]+matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    p[i][j] = k;
                }
            }
        }
        printMatrix(matrix,n);
    }
    return p;
}

vector<int> findPath(int** p,int start,int end){

    if(p[start][end]==start)
    {
        vector<int> ret;
        ret.push_back(start);
        return ret;
    }
    vector<int> first =findPath(p,start,p[start][end]);
    vector<int> second = findPath(p,p[start][end],end);
    for(auto v:second){
        first.push_back(v);
    }
    return first;
}

void mainFloyd(){
    const int n = 4; // Number of vertices in the graph

    // Convert the graph to a 2D array for processing
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            int ra = rand()% 20 ;
            if(i==j)
                ra=0;
            matrix[i][j] = ra;
        }
    }
    // Print the original graph
    cout << "Original Graph:" << endl;
    printMatrix(matrix, n);

    // Call the Floyd function
    int **shortestPaths = Floyd(matrix, n);

    // Print the shortest paths matrix
    cout << "Shortest Paths Matrix:" << endl;
    printMatrix(shortestPaths, n);

    cout<<"The path between node 0->1"<<endl;

    vector<int> path = findPath(shortestPaths,0,1);
    path.push_back(1);
    for (auto v:path) {
        cout<<v<<"->";
    }
    // Cleanup
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
        delete[] shortestPaths[i];
    }
    delete[] matrix;
    delete[] shortestPaths;
}