#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> suf(n + 1);
    vector<int> earliest(n + 1);
    earliest[n] = -1;
    for (int i = n - 1; i >= 0; i--) {
        suf[i].first = suf[i + 1].first;
        suf[i].second = suf[i + 1].second;
        earliest[i] = earliest[i + 1];
        if (s[i] == '(') {
            suf[i].first += 1;
            earliest[i] = i;
        } else {
            suf[i].second += 1;
        }
    }

    int ans = -1;
    int netOpen = 0;
    int match = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == ')') {
            int e = earliest[i];
            if (e != -1 && netOpen + 1 <= suf[e + 1].second) {
                int create = min(netOpen + 1 + suf[e + 1].first, suf[e + 1].second);
                if (2 * create != n) {
                    ans = max(ans, match + 2 * create);
                }
            }
            if (netOpen > 0) {
                match += 2;
                netOpen -= 1;
            }
        } else {
            netOpen += 1;
        }
    }
    cout << ans << '\n';
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}