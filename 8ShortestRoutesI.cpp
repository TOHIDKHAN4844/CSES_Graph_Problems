#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // Adjacency list
    vector<vector<pii>> adj(n + 1);

    // Read input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Distance vector
    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    // Priority queue for Dijkstra (min-heap)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
       // auto [d, node] = pq.top();
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        // If current distance is greater than the stored distance, skip
        if (d > dist[node]) continue;

        for (auto  it: adj[node]) {
            if (dist[node] + it.second < dist[it.first]) {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    // Output shortest distances
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
