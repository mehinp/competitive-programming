#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;

    vector<array<int, 4>> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            pref[i][j] = pref[i - 1][j];
        }
        if (s[i - 1] == '0') {
            if (t[i - 1] == '0') {
                pref[i][0] += 1;
            } else {
                pref[i][1] += 1;
            }
        } else {
            if (t[i - 1] == '0') {
                pref[i][2] += 1;
            } else {
                pref[i][3] += 1;
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int imbalance = abs((pref[r][1] - pref[l - 1][1]) - (pref[r][2] - pref[l - 1][2]));
        int matches = pref[r][0] - pref[l - 1][0] + pref[r][3] - pref[l - 1][3];
        if (matches >= imbalance) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}