#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> blocks;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        blocks.emplace_back(x, y - x + 1);
    }
    vector<pair<int, int>> power;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        power.emplace_back(x, y);
    }

    int dist = 1;
    int ans = 0;
    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && power[j].first < blocks[i].first) {
            pq.push(power[j].second);
            j += 1;
        }
        while (!pq.empty() && dist <= blocks[i].second) {
            dist += pq.top();
            pq.pop();
            ans += 1;
        }
        if (dist <= blocks[i].second) {
            ans = -1;
            break;
        }
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