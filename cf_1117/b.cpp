#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int aTurns = a[n - 1], bTurns = b[m - 1];
    for (int i = 0; i < n - 1; i++) {
        aTurns += (a[i] - a[i + 1] + 1);
    }
    for (int i = 0; i < m - 1; i++) {
        bTurns += (b[i] - b[i + 1] + 1);
    } 
    if (aTurns >= bTurns) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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