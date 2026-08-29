#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    


    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            if (i + len - 1 >= n) continue;
            
        }
    }
    cout << dp[0][n - 1].first - dp[0][n - 1].second << '\n';
}