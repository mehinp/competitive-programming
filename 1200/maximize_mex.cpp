#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e <= n) {
            freq[e] += 1;
        }
    }   
    
    vector<int> modf(n + 1);

    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) {
            if (modf[i % x] < 1) {
                cout << i << '\n';
                return;
            } else {
                modf[i % x] -= 1;
            }
        } else {
            modf[i % x] += freq[i] - 1;
        }
    }
       
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// 0 1 2 0 2 2 2

// 0 1 1 2 3 4 