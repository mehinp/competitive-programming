#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<bool>> valid(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; i++) {
        unordered_set<int> distinct;
        int mn = n + 1;
        int mx = 0;
        for (int j = i; j < n; j++) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            distinct.insert(a[j]);
            if ((mx - mn == j - i) && (int(distinct.size()) == j - i + 1)) {
                valid[mn][mx] = true;
            }
        }
    }

    for (int i = n / 2; i >= 1; i--) {
        for (int l = 1; 2 * i + l - 1 <= n; l++) {
            if (valid[l][l + i - 1] && valid[l + i][2 * i + l - 1]) {
                cout << i << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}