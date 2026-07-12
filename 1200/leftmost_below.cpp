#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long minB = 1e9 + 5;
    for (int i = 0; i < n; i++) {
        if (b[i] - ((b[i] - 1) / 2) > minB) {
            cout << "NO" << '\n';
            return;
        }
        minB = min(minB, b[i]);
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