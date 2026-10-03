#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    double p;
    cin >> p;
    vector<double> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        sum += x;
    }

    cout << fixed << setprecision(12) << p * p / sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}