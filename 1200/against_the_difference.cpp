#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<deque<int>> indices(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        indices[a[i]].push_back(i);
        if (indices[a[i]].size() >= a[i]) {
            if (indices[a[i]].size() == a[i] + 1) {
                indices[a[i]].pop_front();
            }
            if (indices[a[i]].front() == 0) {
                dp[i] = max(a[i], i > 0 ? dp[i - 1] : 0);
            } else {
                dp[i] = max(dp[indices[a[i]].front() - 1] + a[i], dp[i - 1]);
            }
        } else if (i > 0) {
            dp[i] = dp[i - 1];
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}