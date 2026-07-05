#include <bits/stdc++.h>
using namespace std;


// condenses to formula: r^2 + r - pref[r] - l^2 + l + pref[l - 1]
// best l term as you go, compute for each r 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    long long ans = pref[n];
    long long lTerm = 0;
    for (long long i = 1; i <= n; i++) {
        long long rTerm = i * i + i - pref[i];
        lTerm = max(lTerm, -(i * i) + i + pref[i - 1]);
        ans = max(pref[n] + rTerm + lTerm, ans);
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