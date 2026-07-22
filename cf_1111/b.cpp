#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    if (k == 1) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            cout << m << ' ';
        }
    } else if (k <= m) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            if (i % k == 0) {
                cout << m - (k - 1) << ' '; 
            } else {
                cout << 1 << ' ';
            }
        }
    } else {
        cout << "NO";
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