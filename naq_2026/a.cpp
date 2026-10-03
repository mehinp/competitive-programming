#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int inv = 166374059;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    n %= MOD;
    int x = n;

    n = n * (x + 1 % MOD) % MOD;
    n = n * (x + 2 % MOD) % MOD;
    cout << n * inv % MOD << '\n';
}