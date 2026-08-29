#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end(), [&](const auto& p1, const auto& p2) {
        if (min(p1[0], p1[1]) == min(p2[0], p2[1])) {
            return max(p1[0], p1[1]) < max(p2[0], p2[1]);
        }
        return min(p1[0], p1[1]) < min(p2[0], p2[1]);
    });
    for (int i = 0; i < n; i++) {
        cout << a[i][0] << ' ' << a[i][1] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}