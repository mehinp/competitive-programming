#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    auto s = a;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) {
            int msb = 0;
            int val = i;
            int cnt = 0;
            while (val > 0) {
                msb = cnt;
                cnt++;
                val /= 2;
            }
            ans = (1 << msb);
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