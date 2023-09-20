#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj, int V) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topologicalOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topologicalOrder.push_back(u);
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topologicalOrder;
}

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v; // Edge from u to v
        adj[u].push_back(v);
    }

    vector<int> topologicalOrder = topologicalSort(adj, V);
    if (topologicalOrder.size() == V) {
        cout << "Topological sorting order:" << endl;
        for (int vertex : topologicalOrder) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
