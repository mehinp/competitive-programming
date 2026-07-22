#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n % 2) {
        cout << "NO" << '\n';
        return;
    }

    int neg = 0;
    for (int val : a) {
        if (val < 0) neg++;
    }

    int pos = n - neg;
    if ((n / 2 - min(pos, neg)) % 2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}