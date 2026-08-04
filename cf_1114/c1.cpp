#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i % 2 == 0) even += 1;
            else odd += 1;
        }
        if (b[i] == '1') {
            if (i % 2 == 0) even -= 1;
            else odd -= 1;
        }
    }

    cout << (even == 0 && odd == 0 ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}