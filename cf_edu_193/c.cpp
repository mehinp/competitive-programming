#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(vector<int>& a, vector<int>& b, int n, int m) {
    int tot = n + m;
    int i = 0;
    int j = 0;
    int a_taken = 0;
    int b_taken = 0;
    int both = 0;
    ll ans = 0;
    int as = a.size();
    int bs = b.size();
    while (a_taken + b_taken + both != tot && (i < as || j < bs)) {
        if (i < as && j < bs) {
            if (a[i] > b[j]) {
                if (a_taken < n) {
                    ans += a[i];
                    a_taken += 1;
                }
                i += 1;
            } else if (b[j] > a[i]) {
                if (b_taken < m) {
                    ans += b[j];
                    b_taken += 1;
                }
                j += 1;
            } else if (a[i] == b[j]) {
                ans += a[i];
                i += 1;
                j += 1;
                both += 1;
            } 
        } else if (i < as) {
            if (a_taken < n) {
                ans += a[i];
                a_taken += 1;
            }
            i += 1;
        } else {
            if (b_taken < m) {
                ans += b[j];
                b_taken += 1;    
            }
            j += 1;
        }
    }
    return ans;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x);
    vector<int> b(y);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    cout << max(f(a, b, n, m - 1), f(a, b, n - 1, m)) << '\n';
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