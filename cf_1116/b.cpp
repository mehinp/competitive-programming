#include <bits/stdc++.h>
using namespace std;

// const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            int good1 = 1;
            int good2 = 1;
            bool which = false;
            for (int j = 0; j < n; j += 2) {
                which = !which;
                if (s[j] == '?') continue;
                if ((s[j] == '1' && which) || (s[j] == '0' && !which)) {
                    good1 = 0;
                }
                if ((s[j] == '1' && !which) || (s[j] == '0' && which)) {
                    good2 = 0;
                }
            }
            ans += good1 + good2;
        } else {
            int good1 = 1;
            int good2 = 1;
            bool which = false;
            for (int j = 1; j < n; j += 2) {
                which = !which;
                if (s[j] == '?') continue;
                if ((s[j] == '1' && which) || (s[j] == '0' && !which)) {
                    good1 = 0;
                }
                if ((s[j] == '1' && !which) || (s[j] == '0' && which)) {
                    good2 = 0;
                }
            }
            ans = ans * (good1 + good2);
        }
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