#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<pair<bool, int>> vis(n + 1);
    auto dfs = [&](auto&& self, int node) -> int {
        vis[node].first = true;
        int best = 0;
        for (int neigh : adj[node]) {
            if (!vis[neigh].first) {
                best = max(best, self(self, neigh) + 1);
            } else {
                best = max(best, vis[neigh].second + 1);
            }
        }
        vis[node].second = max(best, vis[node].second);
        return vis[node].second;
    }; 

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i].first) {
            int res = dfs(dfs, i);
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
}