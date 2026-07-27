#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n - k == 1) {
        cout << -1 << '\n';
        return;
    } else if (k == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << 1;
            } else {   
                cout << 0;
            }
        }
        cout << '\n';
        return;
    }

    int ones = k / 2 + 1;
    int zeros = k / 2 + 1;
    if (k % 2) {
        zeros++;
    }

    string ans = "";
    for (int i = 0; i < ones; i++) {
        ans += '1';
    }
    for (int i = 0; i < zeros; i++) {
        ans += '0';
    }

    int cnt = 0;
    while (ans.length() != n) {
        if (cnt % 2 == 0) {
            ans += '1';
        } else {
            ans += '0';
        }
        cnt++;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}