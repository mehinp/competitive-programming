#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> vals(n + 1);
    for (int i = 1; i <= n; i++ ){
        cin >> vals[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1);
    vector<int> cycle;
    vector<int> parent(n + 1);
    bool seen = false;
    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        for (int neigh : adj[u]) {
            if (vis[neigh] && neigh != parent[u]) {
                if (seen) continue;
                seen = true;
                cycle.push_back(u);
                int p = parent[u];
                while (p != neigh) {
                    cycle.push_back(p);
                    p = parent[p];
                }
                cycle.push_back(neigh);

            } else if (!vis[neigh]) {
                parent[neigh] = u;
                self(self, neigh);
            }
        }
    };

    dfs(dfs, 1);

    queue<pair<int, int>> q;
    fill(vis.begin(), vis.end(), 0);
    for (int c : cycle) {
        q.emplace(c, c);
        vis[c] = 1;
    }

    vector<int> closest(n + 1);
    while (!q.empty()) {
        auto [node, source] = q.front();
        q.pop();
        closest[node] = source;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                q.emplace(neigh, source);
                vis[neigh] = 1;
            }
        }
    }

    map<int, int> freq;
    map<pair<int, int>, int> freq2;
    for (int i = 1; i <= n; i++) {
        freq[vals[i]] += 1;
        auto p = make_pair(vals[i], closest[i]);
        freq2[p] += 1;
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int val = vals[i];
        int target = val - k;
        ll add = 2 * freq[target];
        auto find_p = make_pair(target, closest[i]);
        ll sub = freq2[find_p];
        add -= sub;
        ans += add;
    }
    cout << ans << '\n';
}