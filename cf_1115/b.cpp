#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int zeroDel = 0;
    int oneDel = 0;

    int l = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == '1') {
                oneDel += (i - l - 1);
            } else {
                zeroDel += (i - l - 1);
            }
            l = i;
        }
    }

    if (s[n - 1] == '1') {
        oneDel += (n - l - 1);
    } else {
        zeroDel += (n - l - 1);
    }

    int diff = abs(zeroDel - oneDel);
    if (diff <= 1) {
        cout << zeroDel + oneDel << '\n';
        return;
    } else if (diff <= 3) {
        if (zeroDel > oneDel) {
            if (diff == 2) {
                if (s[0] == '1' || s[n - 1] == '1') {
                    cout << zeroDel + oneDel + 1 << '\n';
                    return;
                }
            } else {
                if (s[0] == '1' && s[n - 1] == '1') {
                    cout << zeroDel + oneDel + 2 << '\n';
                    return;
                }
            }
        } else {
            if (diff == 2) {
                if (s[0] == '0' || s[n - 1] == '0') {
                    cout << oneDel + zeroDel + 1 << '\n';
                    return;
                }
            } else {
                if (s[0] == '0' && s[n - 1] == '0') {
                    cout << oneDel + zeroDel + 2 << '\n';
                    return;
                }
            }
        } 
    }

    cout << -1 << '\n';
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

