#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1);
    vector<long long> realPref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + abs(a[i - 1]);
        realPref[i] = realPref[i - 1] + a[i - 1];
    }

    long long best = realPref[n];
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (pref[i] - a[i] + realPref[n] - realPref[i + 1] > best) {
                best = pref[i] - a[i] + realPref[n] - realPref[i + 1];
                idx = i;
             }
        }
    }

    vector<int> ans;
    int f = 1;
    for (int i = idx - 1; i >= 0; i--) {
        if (a[i] * f > 0) {
            ans.push_back(i + 1);
            f *= -1;
        }
    }
    if (idx != -1) {
        ans.push_back(idx + 1);
    }

    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}