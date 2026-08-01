#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int need = 3 * a - b;
    cout << 3 << '\n';
    cout << need - b << ' ' << b << ' ' << b << '\n';
}