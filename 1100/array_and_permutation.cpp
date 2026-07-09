#include <bits/stdc++.h>
using namespace std;

void solve() {
    // if all the elements in a and b appear in the same order it is always possible
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    while (j < n) {
        while (i < n && a[i] != b[j]) {
            i++;
        }
        if (i == n) {
            cout << "NO" << '\n';
            return;
        }
        
        j++;
        while (j < n && b[j] == b[j - 1]) {
            j++;
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