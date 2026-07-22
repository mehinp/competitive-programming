#include <bits/stdc++.h>
using namespace std;

void solve() {
    // find number of mismatches.
    // if 0, then 0
    // if the mismatches are even, and there are more than 1 (1 / 0) cases, it is possible
    // if the mismatches are odd, and there is 1 (1 / 0) case, it is possible

    // otherwise impossible

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int oz = 0;
    int zz = 0;
    int oo = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == 1) {
                oz++;
            }
        } else if (a[i] == 0) {
            zz++;
        } else if (a[i] == 1) {
            oo++;
        }
    }

    if (zz + oo == n) {
        cout << 0 << '\n';
        return;
    }

    if (oz) {
        if (oz % 2) {
            cout << 1;
        } else {
            cout << 2;
        }
    } else if (zz && oo) {
        cout << 2; 
    } else {
        cout << -1;
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