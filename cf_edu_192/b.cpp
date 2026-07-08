#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0;
    int other = 0;
    int ones = 0;
    bool good = false;
    while (i < n) {
        if (other <= ones && (other != 0 || ones != 0)) {
            good = true;
            break;
        }
        if (a[i] == 1) ones++;
        else other++;
        i++;
    }

    if (!good) {
        cout << "NO" << '\n';
        return;
    }
    while (ones > other && i < n && a[i] == 3) {
        i++;
        other++;
    }

    other = 0;
    int ot = 0;
    good = false;
    while (i < n) {
        if (other <= ot && (other != 0 || ot != 0)) {
            cout << "YES" << '\n';
            return;
        }
        if (a[i] != 3) ot++;
        else other++;
        i++;
    }

    cout << "NO" << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}