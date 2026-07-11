#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n - 1) {
            if (lcm(1LL * gcd(a[i], a[i - 1]), 1LL * gcd(a[i], a[i + 1])) != a[i]) {
                ans++;
            }
        } else if (i == 0) {
            if (gcd(a[i], a[i + 1]) != a[i]) ans++;
        } else if (gcd(a[i], a[i - 1]) != a[i]) ans++;
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