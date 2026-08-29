#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> pos_pref(n + 1);
    vector<ll> pref_max(n + 1);
    for (int i = 1; i <= n; i++) {
        pos_pref[i] = pos_pref[i - 1] + (a[i] > 0 ? a[i] : 0);
    }

    vector<ll> neg_suf(n + 2);
    for (int i = n; i >= 1; i--) {
        neg_suf[i] = neg_suf[i + 1] + (a[i] < 0 ? abs(a[i]) : 0);
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, pos_pref[i] + neg_suf[i + 1]);
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