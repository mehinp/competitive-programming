#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int odd = 0;
    int even = 0;
    int totalOdd = 0;
    int totalEven = 0;

    for (int i = 0; i < 2 * n - 1; i++) {
        if (s[i] == '1' && s[i + 1] == '0') {
            if ((i + 1) & 1) {
                even++;
                odd--;
            } else {
                odd++;
                even--;
            }
        }
    }   

    if (s[2 * n - 1] == '1' && s[0] == '0') {
        odd++;
        even--;
    }

    for (int i = 0; i < 2 * n; i++) {
        if ((i + 1) & 1 && s[i] == '1') {
            totalOdd++;
        } else if (s[i] == '1') {
            totalEven++;
        }
    }

    cout << totalEven + even << ' ' << totalOdd + odd << '\n';
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