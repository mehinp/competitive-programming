#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    array<bool, 2> seen = {false, false};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seen[a[i] & 1] = true;
    }

    if (seen[0] && seen[1]) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    for (int i = 29; i >= 0; i--) {
        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i] - (1 << i));
        }
        ans.push_back((1 << i));
    }
    if (seen[0]) {
        ans.push_back(1);
    }

    cout << int(ans.size()) << '\n';
    for (int x : ans) cout << x << ' ';
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

