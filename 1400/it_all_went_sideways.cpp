#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int suf_min = n + 1;
    int max_f = 0;
    int max_num = 0;
    vector<long long> mins(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf_min = min(suf_min, a[i]);
        mins[suf_min] += 1;
        if (mins[suf_min] > max_f) {
            max_f = mins[suf_min];
            max_num = suf_min;
        }
    }

    mins[max_num - 1] += mins[max_num];
    mins[max_num] = 0;
    long long sub = 0;
    for (int i = 1; i <= n; i++) {
        sub += (i * mins[i]);
    }
    cout << accumulate(a.begin(), a.end(), 0LL) - sub - 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}