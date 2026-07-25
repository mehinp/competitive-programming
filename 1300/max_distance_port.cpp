#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    vector<long long> ans(k + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, long long>> q;
    vector<bool> vis(n);
    q.emplace(0, 0);
    vis[0] = true;

    while (!q.empty()) {
        auto [u, dist] = q.front();
        q.pop();
        ans[a[u]] = max(dist, ans[a[u]]);

        for (int neigh : adj[u]) {
            if (!vis[neigh]) {
                q.emplace(neigh, dist + 1);
                vis[neigh] = true;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}