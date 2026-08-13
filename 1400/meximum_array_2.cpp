#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<bool> cank(n, true);
    vector<bool> lower(n, true);
    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c & 1) {
            for (int i = l - 1; i < r; i++) {
                lower[i] = false;
            }
        } else {
            for (int i = l - 1; i < r; i++) {
                cank[i] = false;
            }
        }
    }

    vector<int> ans(n);
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (!lower[i]) {
            if (cank[i]) {
                ans[i] = k;
            } else {
                ans[i] = k + 1;
            }
        } else {
            ans[i] = prev;
            prev++;
            if (prev == k) {
                prev = 0;
            }
        }
    }


    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}