#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> odds;
    vector<long long> evens;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x & 1) {
            odds.push_back(x);
        } else {
            evens.push_back(x);
        }
        total += x;
    }
    if (odds.empty()) {
        cout << *max_element(evens.begin(), evens.end()) << '\n';
        return;
    } else if (evens.empty()) {
        cout << *max_element(odds.begin(), odds.end()) << '\n';
        return;
    }

    cout << total - odds.size() + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}