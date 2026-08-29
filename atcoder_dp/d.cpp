#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    cin >> n >> W;

    vector<long long> dp(W + 1);
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = W - w; j >= 0; j--) {
            dp[j + w] = max(dp[j + w], dp[j] + v);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}