#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    set<int> seen;
    int first = a[0];
    int last = a[0];    
    for (int i = 1; i < n; i++) {
        if (a[i] <= first || a[i] > last + 1) {
            ans++;
            first = a[i];
        }
        last = a[i];
    }
    ans++;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}