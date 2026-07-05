#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
    }

    int need = pref[n];
    int best = n + 1;
    map<int, int> seen;
    seen[0] = 0;

    for (int i = 0; i <= n; i++) {
        int find = pref[i] - need;
        if (seen.contains(find)) {
            best = min(best, i - seen[find]);
        }
        seen[pref[i]] = i;
    }
    cout << (best == n ? -1 : best) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}