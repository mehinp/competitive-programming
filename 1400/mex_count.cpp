#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }

    vector<int> pref(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        int lower = freq[i];
        int upper = n - i;
        if (lower <= upper) {
            pref[lower] += 1;
            pref[upper + 1] -= 1;
        }
        if (!lower) break;
    }

    for (int i = 0; i <= n; i++) {
        cout << pref[i] << ' ';
        pref[i + 1] += pref[i];
    }
    cout << '\n';
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

