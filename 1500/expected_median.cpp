#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long expo(long long b, long long e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    long long res = expo(b, e / 2);
    res = (res * res) % MOD;
    if (e & 1) {
        res = (res * b) % MOD;
    } 
    return res;
}

void solve() {  
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ones += a[i] == 1;
        zeros += a[i] == 0;
    }

    vector<long long> one_choose;
    vector<long long> zero_choose;
    one_choose.push_back(1);
    zero_choose.push_back(1);
    auto c = [&](long long N, long long K, bool which) -> void {
        if (N - K < K) { 
            K = N - K;
        }
        long long res = 1;
        for (long long i = 1; i <= N; i++) {
            res = (res * (N - i + 1)) % MOD;
            res = (res * expo(i, MOD - 2)) % MOD;
            if (which){ 
                one_choose.push_back(res);
            } else {
                zero_choose.push_back(res);
            }
        }
    };
    c(ones, ones, 1);
    c(zeros, zeros, 0);

    long long ans = 0;
    for (long long i = k / 2 + 1; i <= k; i++) {
        if (i >= int(one_choose.size())) continue;
        if (k - i >= int(zero_choose.size())) continue;
        ans = (ans + one_choose[i] * zero_choose[k - i]) % MOD;
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