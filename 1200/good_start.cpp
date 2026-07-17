#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool ydir = abs(y2 - y1) % b == 0;
    bool xdir = abs(x2 - x1) % a == 0;
    bool ans = true;

    if (x1 == x2) {
        ans = ydir;
    } else if (y1 == y2) {
        ans = xdir;
    } else {
        ans = ydir || xdir;
    }
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}