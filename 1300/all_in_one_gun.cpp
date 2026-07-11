#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;
    vector<ll> a(n);
    multiset<ll> ms;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        ms.insert(a[i]);
    }
    ll time = n * (h / total) + k * (h / total);
    ll change = h % total;
    if (change == 0) {
        cout << time - k << '\n';
        return;
    }

    ll mn = 1e9 + 5;
    ll pref = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        ms.erase(ms.find(a[i])); 
        pref += a[i];
        ll diff = change - pref;
        if (diff <= 0) {
            time += (i + 1);
            break;
        }
        auto it = ms.lower_bound(mn + diff);
        if (it != ms.end()) {
            time += (i + 1);
            break;
        }
    }
    cout << time << '\n';
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}