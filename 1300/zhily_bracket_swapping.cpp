#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            if (s1[i] == '(') {
                a++;
                b++;
            } else {
                a--;
                b--;
            }
        } else {
            swap(s1[i], s2[i]);
            if (a < b) {
                a++;
                b--;
            } else {
                a--;
                b++;
            }
        }
        if (a < 0 || b < 0) {
            cout << "NO" << '\n';
            return;
        }
    }   

    cout << (a == 0 && b == 0 ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


