#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string X;
    cin >> X;

    if (n % 2) {
        if (X[0] == 'b') {
            cout << "NO" << '\n';
            return;
        }
        for (int i = 1; i < n - 1; i += 2) {
            if (X[i] != '?') {
                if (X[i] == X[i + 1]) {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    } else {
        for (int i = 0; i < n - 1; i += 2) {
            if (X[i] != '?') {
                if (X[i] == X[i + 1]) {
                    cout << "NO" << '\n';
                    return;
                }
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