#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }


    if (sum % (n * (n + 1) / 2)) {
        cout << "NO" << '\n';
        return;
    }

    long long w = sum / (n * (n + 1) / 2);

    if ((a[0] - n * w) % (1 - n)) {
        cout << "NO" << '\n';
        return;
    }
    long long x = (a[0] - n * w) / (1 - n);
    long long y = w - x;
    if (x < 0 || y < 0) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if ((i + 1) * x + (n - i) * y != a[i]) {
            cout << "NO" << '\n';
            return;
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