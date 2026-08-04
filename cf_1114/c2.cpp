#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> oddA, oddB, evenA, evenB;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] == '1') {
                evenA.push_back(i);
            }
            if (b[i] == '1') {
                evenB.push_back(i);
            }
        } else {
            if (a[i] == '1') {
                oddA.push_back(i);
            }
            if (b[i] == '1') {
                oddB.push_back(i);
            }
        }
    }

    if (oddA.size() != oddB.size() || evenA.size() != evenB.size()) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for (int i = 0; i < int(oddA.size()); i++) {
        ans += abs(oddA[i] - oddB[i]) / 2;
    }

    for (int i = 0; i < int(evenA.size()); i++) {
        ans += abs(evenA[i] - evenB[i]) / 2;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}