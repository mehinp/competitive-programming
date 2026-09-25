#include <bits/stdc++.h>
using namespace std;

const int nax = 300300;
int spf[nax];

void pre() {
    for (int i = 1; i < nax; i++) {
        spf[i] = i;
    }

    for (int i = 4; i < nax; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i * i < nax; i += 2) {
        if (spf[i] == i) {
            for (int j = i * i; j < nax; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getPrimes(int n) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto primes = getPrimes(x);
    int k = primes.size();
    vector<long long> ans(k);
    
    if (k == 0) {
        cout << 0 << '\n';
        return;
    }

    for (int val : a) {
        for (int i = 0; i < k; i++) {
            if (val % primes[i] == 0) {
                ans[i] += val;
            }
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
    return 0;
}