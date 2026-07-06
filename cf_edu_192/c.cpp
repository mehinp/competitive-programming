#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> buckets;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        buckets[x]++;
    }

    int ans = 0;
    if (k - n >= 0 && ((k - n) % int(buckets.size()) == 0)) {
        ans++;
    }
    int prev = buckets.size();
    while (int(buckets.size())) {
        vector<int> rem;
        for (auto &p : buckets) {
            if (p.second == 1) {
                rem.push_back(p.first);
            } else {
                p.second--;
            }
            n--;
        }
        for (int key : rem) {
            buckets.erase(key);
        }
        if (int(buckets.size()) == 0) break;
        if (prev != buckets.size() || ans == 0) {
            if (k - n >= 0 && ((k - n) % int(buckets.size()) == 0)) {
                ans++;
            }
        }
        prev = buckets.size();
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}