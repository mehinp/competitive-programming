#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] == '1') {
        for (char c : s) {
            if (c == '0') ans += 1;
        }
        cout << ans << '\n';
    } else {
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (s[i] == '0') {
                suf[i] += 1;
            }
        }
        ans = 1e9 + 5;
        int ones = 0;
        for (int i = 0; i < n; i++) {
            ans = min(ans, ones + suf[i + 1]);
            if (s[i] == '1') ones += 1;
        }
        cout << ans << '\n';
    }
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