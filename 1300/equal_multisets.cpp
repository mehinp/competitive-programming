#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    set<int> seen;
    for (int i = 0; i < n; i++) {
        if (i < n - k || i >= k) {
            if (b[i] == -1) {
                b[i] = a[i];
            }
            if (a[i] != b[i]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (seen.contains(b[i])) {
            cout << "NO" << '\n';
            return;
        }
        if (b[i] != -1) {
            seen.insert(b[i]);
        }
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}