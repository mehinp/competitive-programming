#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> seen;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!seen.contains(x)) {
            a.push_back(x);
        }
        seen.insert(x);
    }
    sort(a.begin(), a.end());
    set<int> gone;
    vector<int> b;

    for (int val : a) {
        if (gone.contains(val)) continue;
        for (int i = val; i <= k; i += val) {
            if (!seen.contains(i)) {
                cout << -1 << '\n';
                return;
            }
            gone.insert(i);
        }
        b.push_back(val);
    }

    cout << b.size() << '\n';
    for (int val : b) cout << val << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}