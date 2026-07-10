#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    long long ans = tot;
    vector<long long> diff;
    int x = n;

    while (x > 1) {
        diff.clear();
        for (int i = 1; i < int(a.size()); i++) {
            diff.push_back(a[i] - a[i - 1]);
        }
        long long sum = accumulate(diff.begin(), diff.end(), 0LL);
        ans = max({ans, sum, -sum});
        a.pop_back();
        for (int i = 0; i < int(diff.size()); i++) {
            a[i] = diff[i];
        }
        x--;
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