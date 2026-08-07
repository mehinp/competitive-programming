#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    bool swapped = false;
    if (y > x) {
        swap(x, y);
        swapped = true;
    }

    int y_moves = 0;
    int yc = 0;
    int base = 1;
    while (yc + base <= y) {
        yc += base;
        base += 1;
        y_moves += 1;
    }

    int x_moves = 0;
    int xc = 1;
    base = 1;
    while (xc + y_moves * base <= x) {
        x_moves += 1;
        xc += base;
        base += 1;
    }

    cout << x_moves << ' ' << y_moves << ' ';
    for (int i = 0; i < x_moves; i++) {
        cout << (swapped ? "Y" : "X");
    }
    for (int i = 0; i < y_moves; i++) {
        cout << (swapped ? "X" : "Y");
    }
    cout << '\n';
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