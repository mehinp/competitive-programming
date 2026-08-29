#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    if (x == 1) {
        if (n & 1) {
            cout << n << '\n';
        } else {
            cout << n + 3 << '\n';
        }
        return;
    }
    if (x == 0) {
        if (n == 1) {
            cout << -1 << '\n';
        } else if (n & 1) {
            cout << n + 3 << '\n';
        } else {
            cout << n << '\n';
        }
        return;
    }

    int bits = __builtin_popcount(x);
    if (n <= bits) {
        cout << x << '\n';
        return;
    }

    int ans = x + n - bits;
    if ((n - bits) & 1) {
        ans += 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}