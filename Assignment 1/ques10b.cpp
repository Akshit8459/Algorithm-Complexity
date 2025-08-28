#include <iostream>
#include <vector>
using namespace std;

// Print all length-3 paths in adjacency matrix graph
void printAllPathsLength3Matrix(const vector<vector<int>>& graph) {
    int n = graph.size();
    for (int v0 = 0; v0 < n; v0++) {
        for (int v1 = 0; v1 < n; v1++) {
            if (graph[v0][v1] == 0) continue;
            for (int v2 = 0; v2 < n; v2++) {
                if (graph[v1][v2] == 0) continue;
                for (int v3 = 0; v3 < n; v3++) {
                    if (graph[v2][v3] == 0) continue;
                    cout << v0 << " -> " << v1 << " -> " << v2 << " -> " << v3 << endl;
                }
            }
        }
    }
}

// Print all length-3 paths in adjacency list graph
void printAllPathsLength3List(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    for (int v0 = 0; v0 < n; v0++) {
        for (int v1 : adjList[v0]) {
            for (int v2 : adjList[v1]) {
                for (int v3 : adjList[v2]) {
                    cout << v0 << " -> " << v1 << " -> " << v2 << " -> " << v3 << endl;
                }
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graphMatrix(n, vector<int>(n, 0));
    vector<vector<int>> adjList(n);

    cout << "Enter edges (u v) with 0-based indices:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graphMatrix[u][v] = 1;
        adjList[u].push_back(v);
    }

    cout << "\nPaths of length 3 (using adjacency matrix):" << endl;
    printAllPathsLength3Matrix(graphMatrix);

    cout << "\nPaths of length 3 (using adjacency list):" << endl;
    printAllPathsLength3List(adjList);

    return 0;
}
