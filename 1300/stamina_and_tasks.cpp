#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<double, double>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        double ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, a[i].first + ans * (1 - a[i].second / 100.0));
        }
        cout << setprecision(10) << ans << '\n';
    }
 
}