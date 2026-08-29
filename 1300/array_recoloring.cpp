#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << max(*max_element(a.begin(), a.end() - 1) + a[n - 1], *max_element(a.begin() + 1, a.end()) + a[0]) << '\n';
    } else {
        sort(a.rbegin(), a.rend());
        cout << accumulate(a.begin(), a.begin() + k + 1, 0LL) << '\n';
    }
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