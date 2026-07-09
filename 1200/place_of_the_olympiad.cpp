#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    int l = 0;
    int r = m;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long check = n * (mid * (m / (mid + 1)) + (m % (mid + 1)));
        if (check >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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