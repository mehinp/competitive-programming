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
    
    int xor_total = 0;
    for (int i = 0; i < n; i++) {
        xor_total ^= a[i] ^ b[i];
    }

    for (int i = 19; i >= 0; i--) {
        int mask = (1 << i);
        if (xor_total & mask) {
            for (int j = n - 1; j >= 0; j--) {
                if ((a[j] & mask) ^ (b[j] & mask)) {
                    cout << (j & 1 ? "Mai" : "Ajisai") << '\n'; 
                    return;
                }
            }
        }
    }
    cout << "Tie" << '\n';
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