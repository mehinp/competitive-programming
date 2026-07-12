#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    int ans = 0;
    for (int i = 0; i < n; i++) {
            vector<int> tables(x);
            int end = x - 1;
            int beg = end;
            for (int j = 0; j <= i; j++) {
                if (u[j] != 'E') {
                    if (end < 0) continue;
                    if (tables[end] == 0) {
                        tables[end] = 1;
                    }
                    end--;
                } else {
                    if (beg < 0) continue;
                    if (tables[beg] != 0 && tables[beg] < s) {
                        tables[beg] += 1;
                        if (tables[beg] == s) {
                            beg--;
                        }
                    }
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (u[j] == 'I') {
                    if (end < 0) continue;
                    if (tables[end] == 0) {
                        tables[end] = 1;
                    }
                    end--;
                } else {
                    if (beg < 0) continue;
                    if (tables[beg] != 0 && tables[beg] < s) {
                        tables[beg] += 1;
                        if (tables[beg] == s) {
                            beg--;
                        }
                    }
                }
            }
            ans = max(ans, accumulate(tables.begin(), tables.end(), 0));
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