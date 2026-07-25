#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> present(n, vector<bool>(26));
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            present[i][s[i] - 'a'] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (n % i) continue;
        string res = "";
        for (int x = 0; x < i; x++) {
            for (int c = 0; c < 26; c++) {
                bool charWorks = true;
                for (int y = x; y < n; y += i) {
                    if (!present[y][c]) {
                        charWorks = false;
                        break;
                    }
                }
                if (charWorks) {
                    res += (c + 'a');
                    break;
                }
            }
        }
        if (res.length() == i) {
            string ans = "";
            for (int j = 0; j < n / i; j++) {
                ans += res;
            }
            cout << ans << '\n';
            return;
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