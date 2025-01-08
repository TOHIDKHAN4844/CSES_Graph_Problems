#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

signed main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);
    vector<int> visited(nodes + 1, 0);
    vector<pair<int, int>> result;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            if (i != 1) {
                result.push_back({i - 1, i});
            }
            dfs(i, visited, graph);
        }
    }

    cout << result.size() << endl;
    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
