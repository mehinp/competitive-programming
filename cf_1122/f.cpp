#include <bits/stdc++.h>
using namespace std;

const int nax = 3e5;
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    priority_queue<pair<int, int>> freq;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
        freq.emplace(y, x);
    }

    int ans = (--mp.end())->first;

    for (int i = 0; i <= nax; i++) {
        if (!mp.contains(i)) {
            if (freq.empty()) break;
            auto max_f = freq.top();
            freq.pop();
            if (max_f.first == 1 && max_f.second < i) break;
            mp[max_f.second] -= 1;
            if (mp[max_f.second] == 0) mp.erase(max_f.second);
            if (max_f.first != 1) {
                max_f.first -= 1;
                freq.push(max_f);
            }
        }  
        ans = max(ans, i + 1);
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