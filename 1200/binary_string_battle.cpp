#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ones = 0;
    for (char c : s) {
        ones += (c - '0');
    }
    if (ones <= k || 2 * k > n) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}