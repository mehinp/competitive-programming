#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long t, h, u;
    cin >> t >> h >> u;

    long long tu = min(t, u);
    t -= tu;
    u -= tu;
    long long ans = 4 * tu;

    long long tht = min(t / 2, h);
    ans = ans + 7 * tht;
    
    h -= tht;
    t = t - 2 * tht;
    if (h > 0 && t % 2) {
        assert(t == 1);
        ans += 5;
        t = 0;
        h--;
    }

    long long tt = 0;
    if (t) {
        tt += 3;
        t--;
    }   
    tt = tt + 2 * t;
    ans = ans + tt + 3 * h + 3 * u;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}