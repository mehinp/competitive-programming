#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;
const int nax = 100100;
int dp[nax];
int pref[nax];
int k;
void solve() {
    int a, b;
    cin >> a >> b;
    cout << (pref[b] - pref[a - 1] + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int t;
    cin >> t;
    cin >> k;  
    dp[0] = 1;
    for (int i = 1; i < nax; i++) {
        dp[i] = dp[i - 1];
        if (i - k >= 0) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }
    }
    for (int i = 1; i < nax; i++) {
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }
    while (t--) {
        solve();
    }
    return 0;
}