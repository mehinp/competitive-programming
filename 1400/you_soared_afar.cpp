#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> mpa(n + 1);
    vector<int> mpb(n + 1);
    int same = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        mpa[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mpb[b[i]] = i;
        if (mpa[b[i]] == i) {
            same += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[mpa[b[i]]] != a[i] || a[mpb[a[i]]] != b[i]) {
            bad = true;
        } 
    }

    vector<pair<int, int>> ans;
    if (n & 1) {
        if (same != 1) {
            bad = true;
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i]) {
                    if (i != n / 2) {
                        swap(a[n / 2], a[i]);
                        swap(b[n / 2], b[i]);
                        mpa[a[n / 2]] = n / 2;
                        mpa[a[i]] = i;
                        mpb[b[n / 2]] = n / 2;
                        mpb[b[i]] = i;
                        ans.emplace_back(min(n / 2 + 1, i + 1), max(n / 2 + 1, i + 1));
                    }
                }
            }
        }
    } else if (same > 0) {
        bad = true;
    }
    if (bad) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n / 2; i++) {   
        int a_idx = mpa[b[i]];
        int go_to = n - 1 - i;
        if (a[go_to] == b[i]) continue;
        swap(a[a_idx], a[go_to]);
        swap(b[a_idx], b[go_to]);
        mpa[a[a_idx]] = a_idx;
        mpa[a[go_to]] = go_to;
        mpb[b[a_idx]] = a_idx;
        mpb[b[go_to]] = go_to;
        ans.emplace_back(a_idx + 1, go_to + 1);
    }
    cout << int(ans.size()) << '\n';
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
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