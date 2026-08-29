#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a.begin(), a.end());
    long long delta = INT_MAX;
    long long ans = a[n - 1].second - a[n - 1].first;
    for (int i = 0; i < n - 1; i++) {
        vector<long long> tmp = {a[i].first, a[i].second, a[i + 1].second, a[i + 1].first};
        sort(tmp.begin(), tmp.end());
        long long option = tmp[3] - tmp[0] + tmp[2] - tmp[1];
        long long cur = a[i].second - a[i].first + a[i + 1].second - a[i + 1].first;
        delta = min(delta, option - cur);
        ans += a[i].second - a[i].first;
    }
    cout << ans + delta << '\n';
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