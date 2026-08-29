#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    multiset<int> modsB;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        modsB.insert(b[i] % k);
    }

    for (int i = 0; i < n; i++) {
        int ab = a[i] - (a[i] / k) * k;
        ab -= k;
        if (modsB.contains(a[i] % k)) {
            modsB.erase(modsB.find(a[i] % k));
        } else if (modsB.contains(abs(ab) % k)) {
            modsB.erase(modsB.find(abs(ab) % k));
        } else {
            cout << "NO" << '\n';
            return; 
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