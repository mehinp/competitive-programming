#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vector<int> prefA(n);
    vector<int> prefB(m);
    prefA[0] = a[0] - '0';
    prefB[0] = b[0] - '0';
    for (int i = 1; i < n; i++) {
        prefA[i] = (prefA[i - 1] + (a[i] - '0')) % 10;
    }

    for (int i = 1; i < m; i++) {
        prefB[i] = (prefB[i - 1] + (b[i] - '0')) % 10;
    }

    

    if (prefA[n - 1] != prefB[m - 1]) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (prefA[i - 1] == prefB[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}