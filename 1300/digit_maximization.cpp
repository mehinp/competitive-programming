#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int best = s[i] - '0';
        int best_idx = i;
        for (int j = i; j < min(n, i + 9); j++) {
            if ((s[j] - '0') - (j - i) > best) {
                best = (s[j] - '0') - (j - i);
                best_idx = j;
            } 
        }
        s[best_idx] = best + '0';

        for (int j = best_idx; j > i; j--) {
            swap(s[j], s[j - 1]);
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