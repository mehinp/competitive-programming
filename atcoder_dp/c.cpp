#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;   
    vector<array<int, 3>> x(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x[i][j];
        }
    }

    vector<array<int, 3>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i - 1][k] + x[i - 1][j], dp[i][j]);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}