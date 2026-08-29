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

    vector<array<ll, 2>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(abs(dp[i - 1][0] + a[i]), abs(dp[i - 1][1] + a[i]));
        dp[i][1] = dp[i - 1][1] + a[i];
    }
    cout << dp[n][0] << '\n';
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