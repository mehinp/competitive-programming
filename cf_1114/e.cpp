#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    multiset<ll> ms;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ms.insert(b[i]);
    }
    vector<ll> ans;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(-sum);
        if (it == ms.end()) {
            cout << -1 << '\n';
            return;
        }
        sum += *it;
        ans.push_back(sum);
        ms.erase(it);
    }

    for (ll x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}