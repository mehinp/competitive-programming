#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int twos = 0;
    int three = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 1) {
            twos++;
        }
        if (x > 2) {
            three++;
        }
    }
    cout << (twos > 1 || three > 0 ? "YES" : "NO") << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}