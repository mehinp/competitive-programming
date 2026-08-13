#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[0][0] = a[0];
    dp[0][1] = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
        dp[i][1] = max({dp[i - 1][1] + a[i], dp[i - 1][0] + a[i] + b[i], a[i] + b[i]});
    }
    
    long long ans = -INF;
    for (int i = 0; i < n; i++) {
        if (k & 1) {
            ans = max(ans, dp[i][1]); 
        } else {
            ans = max(ans, dp[i][0]);
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