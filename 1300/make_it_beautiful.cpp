#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int ans = 0;
    for (int num : a) {
        ll cur = 0;
        ans += __builtin_popcount(num);
        while (1LL << cur <= k) {
            if (num % 2 == 0) {
                pq.push(1LL << cur);
            }
            cur++;
            num /= 2;
        }
    }

    while (!pq.empty()) {
        k -= pq.top();
        if (k < 0) break;
        pq.pop();
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}