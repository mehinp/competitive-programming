#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n;
    cin >> n;
    vector<ll> b(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        freq[b[i]] += 1;
    }

    if (!freq.contains(0)) {
        cout << -1 << '\n';
        return;
    }

    map<ll, ll> ans;
    auto it = freq.begin();
    ll sum = 0;
    ll prev = 0;
    while (it != freq.end()) {
        if (next(it) != freq.end()) {
            auto nxt = next(it);
            ll need = nxt->first - sum;
            if (need % it->second) {
                cout << -1 << '\n';
                return;
            }
            need /= it->second;
            if (need <= prev) {
                cout << -1 << '\n';
                return;
            }
            ans[it->first] = need;
            prev = need;
            sum += need * it->second;
        } else {
            ans[it->first] = prev + 1;
        }
        it++;
    }

    for (int i = 0; i < n; i++) {
        if (!ans.contains(b[i])) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[b[i]] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}