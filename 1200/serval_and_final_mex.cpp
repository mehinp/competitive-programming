#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool foundZero = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) foundZero = true;
    }

    if (!foundZero) {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    } else if ((a[0] == 0 && a[n - 1] != 0) || (a[0] != 0 && a[n - 1] != 0)) {
        cout << 2 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else if (a[0] != 0 && a[n - 1] == 0) {
        cout << 2 << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << 2 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}