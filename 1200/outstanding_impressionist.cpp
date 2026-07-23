#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> single;
    vector<int> cnt(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == a[i].second) {
            if (!cnt[a[i].first]) {
                single.push_back(a[i].first);
            }
            cnt[a[i].first]++;
        } 
    }

    string ans = "";
    sort(single.begin(), single.end());
    for (auto& p : a) {
        int f = p.first;
        int s = p.second;
        if (f == s && cnt[f] == 1) {
            ans += '1';
            continue;
        }
        auto it1 = lower_bound(single.begin(), single.end(), f);
        auto it2 = upper_bound(single.begin(), single.end(), s);
        if (it2 - it1 == s - f + 1) {
            ans += '0';
        } else {
            ans += '1';
        }
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