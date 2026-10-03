#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    bool works = true;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        if (y < x) {
            works = false;
        }
    }
    if (!works) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        bool found = false;
        for (int neigh : adj[i]) {
            if (neigh == i + 1) {
                found = true;
                break;
            }
        } 
        if (!found) ans += 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}