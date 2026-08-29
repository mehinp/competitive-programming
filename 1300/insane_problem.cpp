#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll find_upper(ll l1, ll r1, ll l2, ll r2, ll val) {
    ll ans = 0;
    while (l1 <= r1) {
        ll mid = l1 + (r1 - l1) / 2;
        if (mid * val > r2) {
            r1 = mid - 1;
        } else {
            ans = mid;
            l1 = mid + 1;
        }
    }
    return ans;
}

ll find_lower(ll l1, ll r1, ll l2, ll r2, ll val) {
    ll ans = 0;
    while (l1 <= r1) {
        ll mid = l1 + (r1 - l1) / 2;
        if (mid * val >= l2) {
            ans = mid;
            r1 = mid - 1;
        } else {
            l1 = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    ll ans = 0;
    for (long long i = 1; i * l1 <= r2; i *= k) {
        ll lower = find_lower(l1, r1, l2, r2, i);
        ll upper = find_upper(l1, r1, l2, r2, i);
        if (lower == 0 || upper == 0) continue;
        ans += upper - lower + 1;
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