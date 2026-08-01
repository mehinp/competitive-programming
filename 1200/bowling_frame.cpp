#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long w, b;
        cin >> w >> b;

        long long l = 0;
        long long r = w + b;
        int ans = 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * (mid + 1) / 2 <= w + b) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << '\n';
    }
}