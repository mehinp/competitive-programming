#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        // leave the ith vessel empty

        // compute max going to the right
        vector<ll> rightMax(n);
        int j = n - 1;
        int idx = (i + 1) % n;
        ll mx = -1;
        while (j--) {
            mx = max(mx, h[(idx - 1 + n) % n]);
            rightMax[idx] = mx;
            idx = (idx + 1) % n;
        }


        // compute max going to the left
        vector<ll> leftMax(n);
        j = n - 1;
        idx = (i - 1 + n) % n;
        mx = -1;
        while (j--) {
            mx = max(mx, h[idx]);
            leftMax[idx] = max(mx, h[idx]);
            idx = (idx - 1 + n) % n;
        }
        
        ll sum = 0;
        for (int k = (i + 1) % n; k != i; k = (k + 1) % n) {
            sum += min(rightMax[k], leftMax[k]);
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}