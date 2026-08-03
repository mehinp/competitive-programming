#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    int ans;
    if (rk <= rd) {
        if (rk == rd) {
            if (ck < cd) {
                ans = cd;
            } else {
                ans = n - cd;
            }
        } else {
            if (cd == ck) {
                ans = rd;
            } else if (ck < cd) {
                ans = max(rd, cd);
            } else {
                ans = max(rd, n - cd);
            }
        }
    } else {
        if (cd == ck) {
            ans = n - rd;
        } else {
            if (ck < cd) {
                ans = max(n - rd, cd);
            } else {
                ans = max(n - rd, n - cd);
            }
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