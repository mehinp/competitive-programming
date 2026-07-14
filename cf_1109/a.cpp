#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int mx = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            curr++;
        } else {
            curr = 0;
        }
        mx = max(curr, mx);
    }

    cout << (mx + 1) / 2 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}