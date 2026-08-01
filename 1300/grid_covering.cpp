#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(m, n) <= 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}