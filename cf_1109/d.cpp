#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m + 1);
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }


    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += abs(pref[b[i]] - pref[b[i - 1]]);
    }

    ans += pref[n] - pref[b.back()];
    cout << ans << '\n';
}       

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}