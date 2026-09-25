#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(101);
    int max_f = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
        max_f = max(max_f, freq[a[i]]);
    }

    for (int i = 1; i <= max_f; i++) {
        for (int j = 100; j >= 1; j--) {
            if (freq[j]) {
                cout << j << ' ';
                freq[j] -= 1;
            }
        }
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