#include <bits/stdc++.h>
using namespace std;

#define int long long

bool findPath(int n, vector<int>& visited, vector<vector<int>>& graph, vector<int>& parent, vector<int>& path) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    parent[1] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n) {
            while (curr != -1) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }
    return false;
}

signed main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);
    vector<int> visited(nodes + 1, 0), parent(nodes + 1), path;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (!findPath(nodes, visited, graph, parent, path)) {
        cout << "IMPOSSIBLE";
    } else {
        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
    }

    return 0;
}
