#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> zf(n + 1);
    vector<int> of(n + 1);
    vector<pair<int, int>> blocks;
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            blocks.emplace_back(s[i - 1], i - l);
            l = i;
        }
    }
    blocks.emplace_back(s[n - 1], n - l);

    long long one = 0;
    long long zero = 0;

    
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