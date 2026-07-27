#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2) {
        cout << "NO" << '\n';
        return;
    }

    int mx = 0;
    int mn = 1e9 + 5;
    for (int i = 0; i < n - 1; i += 2) {
        if (a[i] - a[i + 1] < 2) {
            cout << "NO" << '\n';
            return;
        }
        mx = max(mx, a[i + 1]);
        mn = min(mn, a[i]);
    }
    if (mx < mn - 1) {
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