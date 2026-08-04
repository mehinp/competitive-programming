#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int nax = 200200;
int power[nax];
void pre() {
    power[0] = 1;
    for (int i = 1; i < nax; i++) {
        power[i] = (power[i - 1] * 2) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }


    int prev = -3;
    bool neg = false;
    long long ans = 1;
    int adj = 0;
    for (auto& p : freq) {
        if (p.first < 0) neg = true;
        if (prev == p.first - 1) {
            adj += 1;
        } 
        ans = (ans * power[p.second - 1]) % MOD;
        prev = p.first;
    }   

    if (neg) {
        ans = (ans * (adj + 1)) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
}