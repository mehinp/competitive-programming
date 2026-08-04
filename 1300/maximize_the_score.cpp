#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    vector<int> prev(n + 1, -1);
    vector<long long> dp(2 * n);
    dp[0] = 1;
    prev[a[0]] = 0;

    for (int i = 1; i < 2 * n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (prev[a[i]] != -1) {
            long long len = i - prev[a[i]] + 1;
            long long before = 0;
            if (prev[a[i]] > 0) {
                before = dp[prev[a[i]] - 1];
            }
            dp[i] = max(dp[i], len * len + before);
        }
        prev[a[i]] = i;
    }
    cout << dp[2 * n - 1] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}