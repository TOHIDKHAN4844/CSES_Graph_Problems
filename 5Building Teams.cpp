#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isBipartite(int start, vector<int>& visited, vector<vector<int>>& graph, vector<int>& groups) {
    queue<pair<int, int>> q;
    q.push({start, 1});
    visited[start] = 1;
    groups[start] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int team = q.front().second;
        q.pop();

        for (int neighbor : graph[node]) {
            if (groups[neighbor] == team) return false;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                groups[neighbor] = (team == 1) ? 2 : 1; 
                q.push({neighbor, groups[neighbor]});
            }
        }
    }
    return true;
}

signed main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);
    vector<int> visited(nodes + 1, 0), groups(nodes + 1, 0);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i] && !isBipartite(i, visited, graph, groups)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int i = 1; i <= nodes; i++) {
        cout << groups[i] << " ";
    }

    return 0;
}
