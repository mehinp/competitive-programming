#include <bits/stdc++.h>
using namespace std;

int id = 0;
int test = 0;

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

    if (n < 2 * m) {
        cout << "NO" << '\n';
        return; 
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;

    for (int i = 0; i < m; i++) {
        if (a[i] <= b[j] && b[j] <= a[n - m + i]) {
            j += 1;
        }
        if (j == m) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        test++;
        solve();
    }
    return 0;
}
