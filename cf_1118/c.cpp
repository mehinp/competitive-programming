#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int best = 0;
    int node = 1;
    for (int i = 2; i <= n; i++) {
        while (true) {
            cout << "? " << 1 << ' ' << i << ' ' << best + 1 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                best += 1;
                node = i;
                if (best == n - 1) break;
            } else {
                break;
            }
        }
        if (best == n - 1) break;
    }


    int second = 1;
    for (int i = 1; i <= n; i++) {
        if (i == node) continue;
        while (true) {
            cout << "? " << node << ' ' << i << ' ' << best + 1 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                second = i;
                best += 1;
                if (best == n - 1) break;
            } else {
                break;
            }
        }
        if (best == n - 1) break;
    }
    cout << "! " << node << ' ' << second << ' ' << best << endl;
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