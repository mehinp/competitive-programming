#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }  
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] <= b[i]) {
            a[i] = b[i];
            continue;
        }
        a[i - 1] += a[i] - b[i];
    }
    cout << (a[0] > b[0] ? "NO" : "YES") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}   