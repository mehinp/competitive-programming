#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m + 1));
    for (int i = 0; i < n; i++) {
        long long pref = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pref += a[i][j];
        }
        a[i][m] = pref;
    }
    sort(a.begin(), a.end(), [&](auto& first, auto& second){
        return first.back() > second.back();
    }); 


    long long ans = 0;
    int cnt = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = ans + a[i][j] * cnt;
            cnt--;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}