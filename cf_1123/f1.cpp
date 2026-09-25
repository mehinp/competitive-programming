#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> elements;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        elements.push_back(a[i]);
    }

    vector<int> ans(n);
    ans[0] = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

    for (int i = 1; i < 35; i++) {
        vector<int> newE;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                newE.push_back(elements[j] ^ elements[k]);
            }
        }
        sort(newE.begin(), newE.end());
        newE.resize(n);
        if (newE.back() - newE[0] == 0) break;
        ans[i] = newE.back() - newE[0];
        elements = newE;
    }

    while (q--) {
        int x;
        cin >> x;
        x = min(x, n - 1);
        cout << ans[x] << '\n';
    }
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