#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> distinct;
    int l = 0;
    for (int i = 0; i < n; i++) {
        distinct.insert(a[i]);
        if (i - l + 1 == m) {
            if (*distinct.begin() == *prev(distinct.end())) {
                cout << "NO" << '\n';
                return;
            }
            distinct.erase(distinct.find(a[l]));
            l++;
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