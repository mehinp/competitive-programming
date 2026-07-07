#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;


    int ans = -1;
    if (x1 > x2) {
        ans = k + min(x1 - x2, x2 + (n - x1));
    } else {
        ans = k + min(x2 - x1, n - x2 + x1);
    }
    cout << (n == 2 || n == 3 ? 1 : ans) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}