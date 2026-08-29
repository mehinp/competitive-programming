#include <bits/stdc++.h>
using namespace std;

const int nax = 200200;
int a[nax];
int pref[nax];
void pre() {
   auto calc = [&](int num) -> int {
        int res = 0;
        while (num) {
            num /= 3;
            res += 1;
        }
        return res;
    };
    for (int i = 1; i < nax; i++) {
        a[i] = calc(i);
    }
    for (int i = 1; i < nax; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
}

void solve() {
    int l, r;
    cin >> l >> r;

    cout << 2 * a[l] + pref[r] - pref[l] << '\n';
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