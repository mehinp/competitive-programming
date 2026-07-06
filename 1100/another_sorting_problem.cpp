#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];   
    }

    int maxGap = 0;
    for (int i = 1; i < n; i++) {
        maxGap = max(maxGap, a[i - 1] - a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            a[i] += maxGap;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}