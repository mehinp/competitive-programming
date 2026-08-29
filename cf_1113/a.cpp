#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] == '0') {
            s.erase(i, 1);
            break;
        }
    }

    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] == '1') {
            s.erase(i, 1);
            break;
        }
    }
    cout << s << '\n';
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