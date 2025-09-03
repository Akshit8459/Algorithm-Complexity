#include <bits/stdc++.h>
using namespace std;

// -------- Print all paths of length 3 using adjacency matrix --------
void printPathsMatrix(const vector<vector<int>>& mat) {
    int n = mat.size();
    cout << "\nPaths of length 3 (Adjacency Matrix):\n";
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (!mat[a][b]) continue; // (a,b) must be edge
            for (int c = 0; c < n; c++) {
                if (!mat[b][c]) continue; // (b,c) must be edge
                for (int d = 0; d < n; d++) {
                    if (!mat[c][d]) continue; // (c,d) must be edge
                    if (a != b && b != c && c != d) { // avoid trivial repeats
                        cout << "(" << a << " -> " << b 
                             << " -> " << c << " -> " << d << ")\n";
                    }
                }
            }
        }
    }
}

// -------- Print all paths of length 3 using adjacency list --------
void printPathsList(const vector<vector<int>>& adj) {
    int n = adj.size();
    cout << "\nPaths of length 3 (Adjacency List):\n";
    for (int a = 0; a < n; a++) {
        for (int b : adj[a]) {
            for (int c : adj[b]) {
                for (int d : adj[c]) {
                    if (a != b && b != c && c != d) {
                        cout << "(" << a << " -> " << b 
                             << " -> " << c << " -> " << d << ")\n";
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1; // remove this line if directed graph
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed graph
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // Print adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }

    // Print paths
    printPathsMatrix(mat);
    printPathsList(adj);

    return 0;
}
