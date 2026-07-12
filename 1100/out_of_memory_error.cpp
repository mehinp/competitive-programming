#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    vector<int> orig(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        orig[i] = a[i];
    }

    vector<int> lastEdit(n);
    int lastReset = -1;
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        b--;
        a[b] += c;
        if (lastEdit[b] < lastReset) {
            a[b] = orig[b] + c;
        }
        if (a[b] > h) {
            a[b] = orig[b];
            lastReset = i;
        }
        lastEdit[b] = i;
    }

    for (int i = 0; i < n; i++) {
        if (lastEdit[i] < lastReset) {
            a[i] = orig[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}