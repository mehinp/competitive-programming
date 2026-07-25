#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;


    bool zero = false;
    for (int i = (1 << n) - 1; i >= 0; i /= 2) {
        if (zero) break;
        if (i == 0) zero = true;
        for (int j = 0; i + j <= (1 << n) - 1; j += (i + 1) * 2) {
            ans.push_back(i + j);
        }
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}