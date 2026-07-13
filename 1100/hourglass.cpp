#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s, k, m;
    cin >> s >> k >> m;
    int lastFlip = (m / k) * k;
    if (s <= k || (m / k) % 2 == 0) {
        cout << max(0, s - (m - lastFlip)) << '\n';
    } else {
        cout << k - (m - lastFlip) << '\n';
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}