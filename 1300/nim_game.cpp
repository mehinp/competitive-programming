#include <bits/stdc++.h>
using namespace std;

// const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int xorTotal = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xorTotal ^= a[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    } 

    if (xorTotal == 0) {
        cout << 1 << '\n';
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] ^ xorTotal) < a[i]) ans++;
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