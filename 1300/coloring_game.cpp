#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    // 2 3 4 5 7 7

    // The third element must be strictly less than the sum of the first two
    // AND it must be large enough such that the total sum is less than the maximum element

    int n;
    cin >> n;
    vector<int> a(n);   
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int sum = a[i] + a[j];
            int res = -1;
            int l = j + 1;
            int r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (a[mid] < sum) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (res == -1) continue;
            l = j + 1;
            r = res;
            int res2 = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (a[mid] + sum > mx) {
                    res2 = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }   
            if (res2 != -1) {
                ans += res - res2 + 1;
            }
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