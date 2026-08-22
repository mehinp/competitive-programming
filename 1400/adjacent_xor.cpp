#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (a[n - 1] != b[n - 1]) {
        cout << "NO" << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i]) {
            if ((a[i + 1] ^ a[i]) != b[i] && (a[i] ^ b[i + 1]) != b[i]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
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