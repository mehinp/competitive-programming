#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= c;
    }

    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < (n + 1) / 2 || a[i] > 0) {
            ans += a[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}