#include <bits/stdc++.h>
using namespace std;


bool solve() {
    string num;
    cin >> num;

    int sum = 0;
    vector<int> use;
    for (char c : num) {
        if (c == '2' || c == '3') {
            use.push_back(c - '0');
        }
        sum += (c - '0');
    }
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        bool res = solve();
        if (res) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}