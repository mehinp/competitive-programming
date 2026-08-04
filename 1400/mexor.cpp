#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int target = n ^ k;
    if (target < n) {
        cout << "YES" << '\n';
        for (int i = 1; i < n; i++) {
            if (i == target) continue;
            cout << i << ' ';
        }
        cout << 0 << ' ';
        if (target != 0) cout << target;
    } else {
        int x = 1;
        while (x * 2 < n) x *= 2;
        int y = -1;
        for (int i = 1; i < n; i++) {
            if ((i ^ x) == target) {
                y = i;
            }
        }
        if (y == -1) {
            cout << "NO";
        } else {
            cout << "YES" << '\n';
            for (int i = 1; i < n; i++) {
                if (i == x || i == y) continue;
                cout << i << ' ';
            }
            cout << 0 << ' ' << min(x, y) << ' ' << max(x, y);
        }
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