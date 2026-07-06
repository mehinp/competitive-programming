#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(6, 1e9));
    for (int i = 0; i < 6; i++) {
        if (i == a[0] - 1) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        // keep the face of the die
        for (int j = 1; j <= 6; j++) {
            if (a[i] + j == 7 || j == a[i]) continue;
            dp[i][a[i] - 1] = min(dp[i][a[i] - 1], dp[i - 1][j - 1]);
        }

        // change the face of the die
        for (int j = 1; j <= 6; j++) {
            if (j == a[i]) continue;
            for (int k = 1; k <= 6; k++) {
                if (j + k == 7 || j == k) continue;
                dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][k - 1] + 1);
            }
        }
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}