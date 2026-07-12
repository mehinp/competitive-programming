#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long p, q;
    cin >> p >> q;

    if (p >= q || (2 * abs(p - q) > p && 3 * abs(p - q) > q)) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}