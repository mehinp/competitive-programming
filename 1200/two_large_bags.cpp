#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 1) {
            cout << "NO" << '\n';
            return;
        }   
        if (i == n && freq[i] % 2) {
            cout << "NO" << '\n';
            return;
        }
        if (freq[i] - 2 > 0) {
            freq[i + 1] += (freq[i] - 2);
        } 
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}