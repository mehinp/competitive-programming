#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int first = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            first += a[i] - b[i];
        } else {
            first = 1e9;
            break;
        }
    } 

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int second = c;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cout << -1 << '\n';
            return;
        } else {
            second += a[i] - b[i];
        }
    }
    cout << min(first, second) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}