#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<array<double, 2>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][1];
        p[i][0] = 1 - p[i][1];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j <= n; j++) {
                if (j - k >= 0) {
                    dp[i][j] += (dp[i - 1][j - k] * p[i - 1][k]);
                }
            }
        }
    }
    double ans = 0;
    for (int j = n; j >= (n + 1) / 2; j--) {
        ans += dp[n][j];
    }
    cout << setprecision(16) << ans << '\n';
}   