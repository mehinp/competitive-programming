#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i < n - 2) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
    }
    cout << dp[n - 1] << '\n';
}