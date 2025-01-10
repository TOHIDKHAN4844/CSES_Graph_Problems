#include <bits/stdc++.h>
#define int long long
using namespace std;

bool findCycle(int node, int parent, vector<vector<int>>& graph, vector<int>& visited, vector<int>& parents, vector<int>& cycle) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parents[neighbor] = node;
            if (findCycle(neighbor, node, graph, visited, parents, cycle)) {
                return true;
            }
        } else if (neighbor != parent) {
            cycle.push_back(neighbor);
            int cur = node;
            while (cur != neighbor) {
                cycle.push_back(cur);
                cur = parents[cur];
            }
            cycle.push_back(neighbor);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    return false;
}

signed main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);
    vector<int> visited(nodes + 1, 0), parents(nodes + 1, -1), cycle;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i] && findCycle(i, -1, graph, visited, parents, cycle)) {
            cout << cycle.size() << endl;
            for (int node : cycle) cout << node << " ";
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
