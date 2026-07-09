#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    // maintain a multiset of size k and a queue of size n - k

    // initially the multiset has the first k elements

    // choose either the win condition card or the smallest cost card from the multiset

    // remove it

    // add it to the queue

    // add the front of the queue to the multiset

    int n, k, p, m;
    cin >> n >> k >> p >> m;
    int winCost = -1;
    multiset<int> ms;
    queue<int> q;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (i + 1 == p) {
            ms.insert(-1);
            winCost = x;
        } else {
            ms.insert(x);
        }
    }   
    for (int i = k; i < n; i++) {
        int x;
        cin >> x;
        if (i + 1 == p) {
            q.push(-1);
            winCost = x;
        } else {
            q.push(x);
        }
    }

    int ans = 0;
    while (m > 0) {
        int rem = *ms.begin();
        int cost = rem == -1 ? winCost : rem;
        if (m - cost < 0) break;
        m -= cost;
        if (rem == -1) {
            ans++;
        }
        q.push(rem);
        ms.erase(ms.begin());
        ms.insert(q.front());
        q.pop();
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}