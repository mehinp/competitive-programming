#include <bits/stdc++.h>
using namespace std;

int ceil_div(int n, int k) {
    return (n + k - 1) / k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n';
        return;
    }
    set<int> s;
    s.insert(n / k);
    s.insert(ceil_div(n, k));
    int cnt = 1;

    while (*s.begin() > 0 && *s.end() > 0) {
        int first = *s.begin();
        int second = *s.end();
        if (first == k || second == k) {
            cout << cnt << '\n';
            return;
        }
        s.clear();
        s.insert(first / 2);
        s.insert(ceil_div(first, 2));
        s.insert(second / 2);
        s.insert(ceil_div(second, 2));
        ++cnt;
    }   
    cout << -1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}