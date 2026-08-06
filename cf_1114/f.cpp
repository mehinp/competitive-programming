#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int xorA = 0;
    int xorB = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xorA ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        xorB ^= b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        cout << "YES" << '\n';
        return;
    }

    xorA ^= xorB;
    for (int i = 0; i < n; i++) {
        if (a[i] == xorA) {
            vector<int> temp;
            temp.push_back(a[i]);
            for (int j = 0; j < n; j++) {
                if (i != j) temp.push_back(a[i] ^ a[j]);
            }
            sort(temp.begin(), temp.end());
            if (temp == b) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
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
        solve();
    }
    return 0;
}