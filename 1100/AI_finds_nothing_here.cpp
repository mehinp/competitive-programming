#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
using ll = long long;

ll fast_expo(ll a, ll b) {
    if (b == 0) return 1;
    ll temp = fast_expo(a, b / 2);
    temp = (temp * temp) % MOD;
    if (b % 2) {
        temp = (temp * a) % MOD;
    }
    return temp;
}

void solve() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll b = n * m - ((n - r + 1) * (m - c + 1));
    cout << fast_expo(2, b) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}