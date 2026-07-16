#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector<ll> a(n + 1);
    for (int i = 2; i < n; i++) {
        a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    }

    ll other = 0;
    for (int i = 2; i < n; i++) {
        other += (a[i] * (i - 1));
    }
    a[n] = (f[1] - other) / (n - 1);

    other = 0;
    for (int i = 3; i <= n; i++) {
        other += (a[i] * (i - 2));
    }
    a[1] = f[2] - other;

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}