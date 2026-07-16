#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }


    vector<int> cnt(n + 1);
    for (auto &p : freq) {
        int num = p.first;
        for (int i = num; i <= n; i += num) {
            cnt[i] += p.second;
        }
    }
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}