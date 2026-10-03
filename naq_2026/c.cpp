#include <bits/stdc++.h>
using namespace std;

const int nax = 100100;

using ll = long long;
const int MOD = 998244353;

ll fact[nax];
void pre() {
    fact[0] = 1;
    for (int i = 1; i < nax; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    map<pair<ll, ll>, int> same;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first < a[i].second) {
            swap(a[i].first, a[i].second);
        }
        same[a[i]] += 1;
    }
    sort(a.rbegin(), a.rend());

    ll ans = 1;
    if (a[0].first != a[0].second) {
        ans = (ans * 2) % MOD;
    }
    for (int i = 1; i < n; i++) {
        if (a[i].first > a[i - 1].first || a[i].second > a[i - 1].second) {
            cout << 0 << '\n';
            return;
        }
        ll diff = (a[i - 1].first - a[i].first + 1) * (a[i - 1].second - a[i].second + 1) % MOD;
        if (a[i].first != a[i].second && a[i].first <= a[i - 1].second) {
            diff = (diff + (a[i - 1].second - a[i].first + 1) * (a[i - 1].first - a[i].second + 1) % MOD);
        }
        ans = (ans * diff) % MOD;
    }

    for (auto& p : same) {
        ans = (ans * fact[p.second]) % MOD;
    }
    cout << ans << '\n';
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
    return 0;
}
