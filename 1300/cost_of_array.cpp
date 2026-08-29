#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == n) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] != (i + 1) / 2) {
                cout << (i + 1) / 2 << '\n';
                return;
            }
        }
        cout << (n + 2) / 2 << '\n';
    } else {
        int rem = k - 2;
        for (int i = 1; i <= n - rem - 1; i++) {
            if (a[i] != 1) {
                cout << 1 << '\n';
                return;
            }
        }
        cout << 2 << '\n';
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