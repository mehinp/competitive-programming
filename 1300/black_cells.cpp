#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    sort(a.begin(), a.end());   
    if (n % 2 == 0) {
        ll ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            ans = max(ans, a[i + 1] - a[i]);
        }
        cout << ans << '\n';
    } else {
        ll ans = ll(2e18);
        for (int i = 0; i < n; i += 2) {
            ll mx = 0;
            for (int j = 0; j < n - 1; j += 2) {
                if (i == j) {
                    j--;
                    continue;
                }
                mx = max(mx, a[j + 1] - a[j]);
            }
            ans = min(ans, mx);
        }
        cout << ans << '\n';
    }
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