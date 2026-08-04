#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x = {a, b, c};

    sort(x.begin(), x.end());
    if (x[0] == x[1] || x[1] == x[2]) {
        cout << 0 << '\n';
    } else {
        cout << min(x[2] - x[1], x[1] - x[0]) << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}