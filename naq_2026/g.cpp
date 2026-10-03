#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, g;
    cin >> n >> q >> g;

    map<int, int> freq_g;
    map<int, int> which_g;

    while (q--) {
        char which;
        cin >> which;
        if (which == 'P') {
            int s, a;
            cin >> s >> a;
            for (int i = 0; i < a; i++) {
                int x;
                cin >> x;
                if (!which_g.contains(x)) {
                    freq_g[s] += 1;
                    which_g[x] = s;
                } else if (which_g[x] != 's') {
                    int prev = which_g[x];
                    freq_g[prev] -= 1;
                    freq_g[s] += 1;
                    which_g[x] = s;
                }
            }
        } else {
            int s;
            cin >> s;
            cout << freq_g[s];
            if (q != 0) {
                cout << '\n';
            }
        }
    }
    cout << '\n';
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