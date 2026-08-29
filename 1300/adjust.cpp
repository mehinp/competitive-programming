#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<bool> seen(n + 1);
    vector<int> order;
    for (int i = 0; i < m; i++) {
        if (!seen[b[i]]) {
            order.push_back(b[i]);
            seen[b[i]] = 1;
        }
    }
    for (int i = 0; i < min(int(order.size()), n); i++) {
        if (a[i] != order[i]) {
            cout << "TIDAK" << '\n';
            return;
        }
    }
    cout << "YA" << '\n';
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