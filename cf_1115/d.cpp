#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> diff;
    cout << a[0] << ' ';
    ll res = a[0];
    for (int i = 1; i < n - 1; i++) {
        diff.push(a[i] - a[i - 1]);
        if ((a[i - 1] + a[i + 1]) % 2) {
            while (!diff.empty()) {
                res += diff.top();
                cout << res << ' ';
                diff.pop();
            }
        }
    }

    diff.push(a[n - 1] - a[n - 2]);
    while (!diff.empty()) {
        res += diff.top();
        cout << res << ' ';
        diff.pop();
    }
    cout << '\n';
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