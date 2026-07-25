#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);   
    auto s = a;
    sort(s.begin(), s.end());

    long long ans = 0;
    for (long long b : a) {
        auto it1 = lower_bound(s.begin(), s.end(), sum - b - y);
        auto it2 = upper_bound(s.begin(), s.end(), sum - b - x);
        ans += (it2 - it1);
        if ((b >= sum - b - y) && (b <= sum - b - x)) {
            --ans;
        }
    }
    cout << (ans / 2) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}