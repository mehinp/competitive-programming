#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 2; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] == s[i - 2]);
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        int amt = pref[r] - pref[l];
        if (k >= (amt + 1) / 2) {
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