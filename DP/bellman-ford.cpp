//
// Created by seyed on 6/7/2024.
//
using namespace std;
int ** Bellman_ford(vector<pair<int,pair<int,int>>> edges,int n,int source){
    int **r = new int*[2];
    r[0] = new int [n];
    r[1] = new int[n];
    for (int i = 0; i < n; ++i) {
        r[1][i] = -1;
        r[0][i] = 1000000000;
    }

    r[0][source] = 0;

    for (int i = 0; i < n; ++i) {
        for(auto edge : edges){
            if(r[0][edge.second.second] > r[0][edge.second.first] + edge.first){
                r[0][edge.second.second] = r[0][edge.second.first] + edge.first;
                r[1][edge.second.second] = edge.second.first;
            }
        }
    }


    for(auto edge : edges){
        if(r[0][edge.second.second] > r[0][edge.second.first] + edge.first) {
            return nullptr; //negative loop;
        }
    }

    return r;
}

void printDistanceAndPredecessor(int **distances, int **predecessors, int n) {
    cout << "Distances from source:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << distances[0][i] << endl;
    }

    cout << "Predecessors of each node:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << "'s predecessor: Node " << predecessors[1][i] << endl;
    }
}

void mainBellman_ford(){
    vector<pair<int, pair<int, int>>> edges = { {10, {0, 1}}, {20, {1, 2}}, {30, {2, 3}}, {40, {3, 0}},{-10,{0,2}} };
    int n = 4; // Assuming the graph has 4 nodes based on the edges
    int source = 0; // Source node

    // Call the Bellman_ford function
    int **result = Bellman_ford(edges, n, source);

    // Check if result is null (indicating a negative cycle)
    if (result == nullptr) {
        cout << "Negative cycle detected." << endl;
    } else {
        // Print the results
        printDistanceAndPredecessor(result, result, n);

        // Cleanup
        for (int i = 0; i < 2; ++i) {
            delete[] result[i];
        }
        delete[] result;
    }
}