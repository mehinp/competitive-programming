#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    long long ones = 0;
    long long nonOne = 0;
    int numNonOne = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 1) {
            ones++;
        } else {
            numNonOne++;
            nonOne += c[i];
        }
    }

    if (n == 1 && numNonOne) {
        if (c[0] <= 2) {
            cout << 0 << '\n';
            return;
        }
    }


    long long fitOnes = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) continue;
        fitOnes += (c[i] / 2);
        if (numNonOne > 1) {
            fitOnes--;
        }
    }

    cout << nonOne + min(fitOnes, ones) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}