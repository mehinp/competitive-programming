#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 1) continue;
        if (a[i] - (i + 1) < 0) continue;
        a[i + 1] += a[i] - (i + 1);
        a[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] < 0 || a[i] >= a[i + 1]) {
            cout << "NO" << '\n';
            return;
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