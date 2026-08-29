#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n;
    cin >> n;

    vector<ll> use;
    ll first = 0;
    for (ll i = 60; i >= 0; i--) {
        if (n & (1 << i)) {
            if (first == 0) {
                first = (1 << i);
            } else {
                use.push_back(1 << i);
            }
        }   
    }

    use.push_back(0);
    vector<ll> ans;
    int m = use.size();
    auto s = [&](auto&& self, ll k, ll val) -> void {
        if (k >= m) {
            ans.push_back(first + val);
            return;
        }

        val += nums[k];
        self(self, k + 1, val);
        val -= nums[k];
        self(self, k + 1, val);
    };

    cout << n - first << '\n';
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << '\n';


    10111


    7 -> (3, 4) (5, 6)

     


    10111
    10110
    10100
    10011
    00111
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