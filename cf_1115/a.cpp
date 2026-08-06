#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> freq(1001);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }

    int card = -1;
    int f = 0;
    int ans = 0;
    while (true) {
        f = 0;
        int which = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != card ) {
                if (freq[a[i]] > f) {
                    which = a[i];
                    f = freq[a[i]];
                }
            }
        }
        if (which == -1) {
            if (card != -1 && freq[card] > 0) {
                ans += card;
            }
            break;
        } else {
            freq[which] -= 1;
            ans += which;
            card = which;
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