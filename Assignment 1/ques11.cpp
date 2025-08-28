#include <iostream>
#include <vector>
using namespace std;

bool dfsCycleCheck(int v, const vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfsCycleCheck(u, adj, visited, recStack)) 
                return true;
        } else if (recStack[u]) {
            // Found a back edge → cycle
            return true;
        }
    }

    recStack[v] = false; // Remove from recursion stack
    return false;
}

bool containsCycle(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(i, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) as directed edge from u to v (0-based indices):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (containsCycle(V, adj))
        cout << "Graph contains cycle." << endl;
    else
        cout << "Graph does not contain cycle." << endl;

    return 0;
}
