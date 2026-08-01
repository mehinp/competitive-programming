#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }

    int ans = -INF;
    for (int i = 0; i < n; i++) {
        int cand = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cand += a[j][0] + a[j][1];
            }  else {
                cand += max(a[j][0], a[j][1]);
            }
        }
        ans = max(ans, cand);
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