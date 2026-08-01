#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2) {
        cout << l << '\n';
        return;
    }

    ll base = 1;
    while (base <= l) {
        base *= 2;
    }

    if (base > r || n == 2) {
        cout << -1 << '\n';
    } else {
        cout << (k <= n - 2 ? l : base) << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}