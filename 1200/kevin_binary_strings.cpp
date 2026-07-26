#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int firstZero = -1;
    string cmp = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            firstZero = i;
        }
        if (firstZero != -1) {
            cmp += s[i];
        }
    }

    int len = cmp.length();
    string temp = "";
    string ans = "";
    pair<int, int> idx;
    for (int i = 0; i < n; i++) {
        temp += s[i];
        if (i + 1 >= len) {
            string num = "";
            for (int j = 0; j < len; j++) {
                if (temp[j] == cmp[j]) {
                    num += '0';
                } else {
                    num += '1';
                }
            }
            if (num > ans) {
                idx.first = i - len + 1;
                idx.second = i;
                ans = num;
            }
            temp.erase(0, 1);
        }
    }

    cout << 1 << ' ' << n << ' ' << idx.first + 1 << ' ' << idx.second + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}