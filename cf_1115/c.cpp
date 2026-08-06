#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> stability(n);
    for (int i = 0; i < n; i++) {
        cin >> stability[i];
    }
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    multiset<ll> ms;
    vector<vector<ll>> pref(n, vector<ll>(m + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (ms.size() < m) {
                ms.insert(a[i][j]);
            } else if (a[i][j] > *ms.begin()) {
                ms.erase(ms.begin());
                ms.insert(a[i][j]);
            }
        }
        vector<ll> elements;
        auto it = ms.begin();
        while (it != ms.end()) {
            elements.push_back(*it);
            it++;
        }
        reverse(elements.begin(), elements.end());
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j - 1] + elements[j - 1];
        }
    }

    int ans = m;
    ll minStability = 1e9 + 5;
    for (int i = 0; i < n; i++) {
        minStability = min(minStability, stability[i]);
        for (int j = 1; j <= m; j++) {
            if (pref[i][j] >= minStability) {
                ans = min(ans, j);
            }
        }
    }
    cout << ans << '\n';
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