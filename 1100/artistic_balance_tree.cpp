#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> odds;
    vector<long long> evens;
    vector<int> b(m);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2) {
            odds.push_back(x);
        } else {
            evens.push_back(x);
        }
        total += x;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        b[i] = x;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    
    int oddPtr = 0;
    int evenPtr = 0;
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    for (int op : b) {
        if (op % 2) {
            if (oddPtr >= int(odds.size())) continue;
            if (odds[oddPtr] > 0) {
                total -= odds[oddPtr];
            } else if (oddPtr == 0) {
                total -= odds[0];
            }
            oddPtr++;
        } else {
            if (evenPtr >= int(evens.size())) continue;
            if (evens[evenPtr] > 0) {
                total -= evens[evenPtr];
            } else if (evenPtr == 0) {
                total -= evens[0];
            }
            evenPtr++;
        }
    }
    cout << total << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}