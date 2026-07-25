#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans = lcm(a[i] / gcd(a[i], a[i + 1]), ans);
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