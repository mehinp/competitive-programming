#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int change = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) change++;
    }
    cout << (change == 1 ? 2 : 1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}