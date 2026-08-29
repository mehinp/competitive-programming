#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> dp(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i].first = max({dp[i - 1].first, a[i - 1], dp[i - 1].second + a[i - 1]});
        dp[i].second = max(dp[i - 1].second, dp[i - 1].first - a[i - 1]);
        ans = max({ans, dp[i].first, dp[i].second});
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