#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int k = 0;
    while ((k + 1) * (k + 2) / 2 <= x + y) {
        k += 1;
    }

    int sum = k * (k + 1) / 2;
    int x1 = x;
    int y1 = max(0, sum - x);

    int x2 = max(0, sum - y);
    int y2 = y;

    string ans = "";
    for (int i = k; i >= 1; i--) {
        if ( >= i) {
            xc -= i;
            ans += 'X';
        } else {
            yc -= i;
            ans += 'Y';
        }
    }
    cout << ans << '\n';
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