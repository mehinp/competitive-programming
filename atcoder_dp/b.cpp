#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= min(n - 1, i + k); j++) {
            dp[j] = min(dp[j], dp[i] + abs(a[j] - a[i]));
        }
    }
    cout << dp[n - 1] << '\n';
}
