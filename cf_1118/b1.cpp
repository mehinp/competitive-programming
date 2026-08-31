#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> freq(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    long long ans = 0;
    int tot = 0;
    for (int i = 0; i <= m; i++) {
        long long cand = n - tot;
        if (2 * i <= m) {
            cand += freq[2 * i];
        }
        ans = max(ans, cand);
        tot += freq[i];
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