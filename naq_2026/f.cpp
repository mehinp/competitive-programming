#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> ans(4);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 1 && x <= 10) {
            ans[0] = 1;
        } else if (x >= 11 && x <= 20) {
            ans[1] = 1;
        } else if (x >= 21 && x <= 30) {
            ans[2] = 1;
        } else {
            ans[3] = 1;
        }
    }
    int res = 0;
    for (int v : ans) {
        res += v;
    }
    cout << res << '\n';
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