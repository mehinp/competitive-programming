#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.push(x);
    }

    bool alice = true;
    while (!a.empty() && !b.empty()) {
        if (alice) {
            if (a.top() >= b.top()) {
                b.pop();
            } else {
                int newB = b.top() - a.top();
                b.pop();
                b.push(newB);
            }
        } else {
            if (b.top() >= a.top()) {
                a.pop();
            } else {
                int newA = a.top() - b.top();
                a.pop();
                a.push(newA);
            }
        }
        alice = !alice;
    }

    cout << (a.empty() ? "Bob" : "Alice") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}