#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(k + 1);

    for (int i = 1; i <= k; i++) {
        for (int val : a) {
            if (i - val >= 0 && !dp[i - val]) {
                dp[i] = 1;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << '\n';
}