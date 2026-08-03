#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, m;
    cin >> x >> m;

    int ans = 0;
    for (int i = 1; i <= min(2 * x, m); i++) {
        int div = x ^ i;
        if (div == 0) continue;
        if (i % div == 0 || x % div == 0) {
            ans++;
        }
    }   
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}