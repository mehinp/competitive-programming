#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int best = n + 1;
    string ans = "";
    for (int i = -1; i < n; i++) {
        stack<char> stk;
        string res = "";
        int cur = 0;
        int x = k;
        for (int j = 0; j <= i; j++) {
            if (s[j] == '(' && x > 0) {
                x--;
                res += '1';
            } else if (s[j] == '(') {
                stk.push(s[j]);
                res += '0';
            } else {
                res += '0';
                if (!stk.empty()) {
                    cur += 2;
                    stk.pop();
                }
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (s[j] == '(') {
                stk.push(s[j]);
                res += '0';
            } else if (!stk.empty() && x > 0) {
                x--;
                res += '1';
            } else {  
                res += '0';
                if (!stk.empty()) {
                    cur += 2;
                    stk.pop();
                }
            }
        }

        if (cur < best) {
            best = cur;
            ans = res;
        }
    }   

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


