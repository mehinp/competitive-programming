#include <bits/stdc++.h>
using namespace std;

const int nax = 200200;
bool is_prime[nax];
const int INF = 1e9 + 5;
void pre() {
    for (int i = 2; i < nax; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < nax; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < nax; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> dp(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            dp[i] = 0;
        } else {    
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (is_prime[j]) {
                        dp[i] = min(dp[i], dp[i / j] * j + 1);
                    }
                    if (is_prime[i / j]) {
                        dp[i] = min(dp[i], dp[j] * (i / j) + 1);
                    }
                }
            }
        }  
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[a[i]];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
    return 0;
}