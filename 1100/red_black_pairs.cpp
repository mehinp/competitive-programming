#include <bits/stdc++.h>
using namespace std;

void solve() {  
    int n;
    cin >> n;
    vector<char> top(n);
    vector<char> bot(n);
    for (int i = 0; i < n; i++) {
        cin >> top[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> bot[i];
    }

    //  BB, BR, RB, RR
    if (n == 1) {
        cout << (top[0] == bot[0] ? 0 : 1) << '\n';
        return;
    }

    vector<string> pairs = {"BB", "BR", "RB", "RR"};
    vector<array<int, 4>> dp(n + 1);
    for (int i = 0; i < 4; i++) {
        dp[0][i] = 0;
        if (pairs[i][0] != top[0]) {
            dp[1][i]++;
        }
        if (pairs[i][1] != bot[0]) {
            dp[1][i]++;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (pairs[j][0] != top[i - 1]) {
                dp[i][j]++;
            }
            if (pairs[j][1] != bot[i - 1]) {
                dp[i][j]++;
            }
        }

        int BR = 0;
        int RB = 0;
        if (top[i - 2] != 'B') {
            BR++;
        } else {
            RB++;
        }
        if (bot[i - 2] != 'R') {
            BR++;
        } else {
            RB++;
        }
        

        dp[i][1] += BR + (i != 3 ? *min_element(dp[i - 2].begin(), dp[i - 2].end()) : min(dp[i - 2][0], dp[i - 2][3]));
        dp[i][2] += RB + (i != 3 ? *min_element(dp[i - 2].begin(), dp[i - 2].end()) : min(dp[i - 2][0], dp[i - 2][3]));
        
        if (i == 2) {
            dp[i][0] += min(dp[i - 1][0], dp[i - 1][3]);
            dp[i][3] += min(dp[i - 1][0], dp[i - 1][3]);
            continue;
        } 
        dp[i][0] += *min_element(dp[i - 1].begin(), dp[i - 1].end());
        dp[i][3] += *min_element(dp[i - 1].begin(), dp[i - 1].end());
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}