#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l < r) {
        if (s[l] != s[r]) {
            if (s[l] == c || s[r] == c) ans += 1;
            else ans += 2;
        }
        l += 1;
        r -= 1;
    }
    cout << ans << '\n';
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