#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    int g = gcd(x, y);

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            int diff = abs(a[i] - (i + 1));
            if (diff % g != 0) {
                cout << "NO" << '\n';
                return;
            }
        }
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