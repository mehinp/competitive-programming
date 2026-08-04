#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    int idx = -1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i - 1] && (s[i] != s[i + 1])) {
            if (s[i - 1] == s[i + 1]) {
                idx = i;
            } else if (idx == -1) {
                idx = i;
            }
        }
    }

    if (idx != -1) {
        s.erase(idx, 1);
    }

    int blocks = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            blocks++;
        }
    }
    blocks += 1;
    cout << blocks << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}