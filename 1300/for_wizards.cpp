#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int best = 0;
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
        int less = 0;
        int greater = 0;
        for (int j = i; j < n; j++) {
            if (a[j] < a[i]) {
                less++;
            } else if (a[j] > a[i]) {
                greater++;
            }
            if (less - greater > best) {
                best = less - greater;
                ans.first = i;
                ans.second = j;
            }
        }
    }

    cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
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