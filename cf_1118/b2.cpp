#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;   
    cin >> n >> m;
    vector<int> a(n);
    vector<int> freq(m + 1);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
        sum += a[i];
    }
    vector<long long> pref(m + 1);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + freq[i];
    }

    vector<long long> ans(m + 1);
    for (int i = 1; i <= min(m, 18); i++) {
        long long k = (1LL << i);
        for (int j = 1; j <= m; j++) {
            long long res = 0;
            if (k * j <= m) {
                res += (pref[m] - pref[k * j - 1]) * (k - 1);
                res += pref[k * j] - pref[k * j - 1];
            }

            for (int y = 1; y < k; y++) {
                long long L = 1LL * y * j;
                long long R = L + j - 1;
                if (R < k * j && R <= m) {
                    res += (pref[R] - pref[L - 1]) * y;
                } else {
                    break;
                }
            }
            ans[i] = max(ans[i], min(sum, res));
        }
    }
    for (int i = 1; i <= min(18, m); i++) {
        cout << ans[i] << ' ';
    }
    for (int i = 19; i <= m; i++) {
        cout << sum << ' ';
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