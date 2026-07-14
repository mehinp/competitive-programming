#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    long long dp0 = 0;
    long long dp1 = LLONG_MIN / 2;
    for (int i = n; i >= 1; i--) {
        long long val = a[i - 1];
        long long p1 = LLONG_MIN / 2, p2 = LLONG_MIN / 2;
        if (b.contains(i)) {
            p1 = dp1;
            p2 = dp0;
        }
        long long newDp0 = val + max(dp0, p1);
        long long newDp1 = -val + max(dp1, p2);
        dp0 = newDp0;
        dp1 = newDp1;
    }

    cout << max(dp0, dp1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}