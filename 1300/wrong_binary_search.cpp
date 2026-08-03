#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    cin >> s;

    if ((s[1] == '1' && s[0] == '0') || (s[n - 1] == '0' && s[n - 2] == '1')) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') {
            cout << "NO" << '\n';
            return;
        }
    }


    int z = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i] = i + 1;
            int num = i;
            for (int j = z; j < i && j >= 0; j++) {
                a[j] = num;
                num--;
            }
            z = -1;
        } else if (z == -1) {
            z = i;
        }
    }

    if (z != -1) {
        int num = n;
        for (int i = z; i < n; i++) {
            a[i] = num;
            num--;
        }
    }

    cout << "YES" << '\n';
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}