#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w;
    cin >> n >> w;  
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    const int MAXN = 100000;
    vector<pair<bool, int>> dp(MAXN + 1);

    dp[0].first = true;
    for (int i = 1; i <= n; i++) {
        for (int j = MAXN; j >= 0; j--) {
            if (dp[j].first && dp[j].second + a[i].first <= w) {
                if (j + a[i].second <= MAXN) {
                    if (!dp[j + a[i].second].first) {
                        dp[j + a[i].second].first = true;
                        dp[j + a[i].second].second = dp[j].second + a[i].first;
                    } else {
                        dp[j + a[i].second].second = min(dp[j + a[i].second].second, dp[j].second + a[i].first);
                    }
                }
            }
        }
    }

    for (int i = MAXN; i >= 0; i--) {
        if (dp[i].first) {
            cout << i << '\n';
            return 0;
        }
    }
}