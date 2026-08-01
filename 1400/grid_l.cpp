#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p, q;
    cin >> p >> q;

    for (int n = 1; (p + 2 * q - n) / (2 * n + 1) > 0; n++) {
        if ((p + 2 * q - n) % (2 * n + 1) != 0) {
            continue;
        } else {
            int m = (p + 2 * q - n) / (2 * n + 1);
            cout << m << ' ' << n << '\n';
        }
    }
    cout << -1 << '\n';
}

int main() {  
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}