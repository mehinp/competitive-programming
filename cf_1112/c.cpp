#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    auto check = [&](int m) -> bool {
        int j = 1;
        for (int i = 0; i < n; i++) {
            if ((j < a[i][0] || j > a[i][1]) && (m - j + 1 < a[i][2] || m - j + 1 > a[i][3])) {
                j++;
            }
        }
        return j - 1 >= m;
    };

    for (int i = n; i >= 0; i--) {
        if (check(i)) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}