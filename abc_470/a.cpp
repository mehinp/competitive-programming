#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 3) {
            cout << i << '\n';
        } else {
            cout << "Fizz" << '\n';
        }
    }
}