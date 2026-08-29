#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;   
    if (n & 1) {
        if (n < 27) {
            cout << -1;
        } else {
            vector<int> ans(n);
            ans[0] = 1;
            ans[9] = 1;
            ans[25] = 1;
            for (int i = 2; i < 9; i += 2) {
                ans[i] = i;
                ans[i - 1] = i;
            }
            for (int i = 11; i < 25; i += 2) {
                ans[i] = i;
                ans[i - 1] = i;
            }

            for (int i = 28; i < n; i += 2) {
                ans[i] = i;
                ans[i - 1] = i;
            }
            ans[22] = 22;
            ans[26] = 22;
            ans[23] = 23;
            ans[24] = 23;

            for (int x : ans) cout << x << ' ';
        }
    } else {
        for (int i = 0; i < n; i += 2) {
            cout << (i + 1) << ' ' << (i + 1) << ' ';
        }
    }
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