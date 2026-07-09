#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int diff = abs(x - y);

    int ans = 0;
    for (int i = 1; i <= diff; i++) {
        if (diff % i == 0) {
            ans++;
        }
    }

    if (diff == 0) {
        cout << 1 << '\n';
    } else {
        cout << ans << '\n';
    }
    for (int i = 0; i < x; i++) {
        cout << 1 << ' ';
    }
    for (int i = 0; i < y; i++) {
        cout << -1 << ' ';
    }
    cout << '\n';
}



int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}