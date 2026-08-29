#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll S;
    int q;
    cin >> S >> q;
    vector<ll> factors;
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            factors.push_back(i);
            if (i * i != S) {
                factors.push_back(S / i);
            }
        }
    }

    sort(factors.begin(), factors.end());
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto x_it = lower_bound(factors.begin(), factors.end(), x);
        auto y_it = lower_bound(factors.begin(), factors.end(), y);
        if (x_it == factors.end()) {
            x_it--;
        }
        if (y_it == factors.end()) {
            y_it--;
        }
        int x_pos = *x_it;
        int y_pos = *y_it;
        

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