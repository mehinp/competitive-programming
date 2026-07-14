#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    long long dist = (qx - px) * (qx - px) + (qy - py) * (qy - py);
    long long sum = 0;
    long long mx = 0;
    for (int i = 0; i < n; i++) {   
        long long x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }   


    int other = max(0LL, 2 * mx - sum);

    if (dist > sum * sum || other * other > dist ) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}