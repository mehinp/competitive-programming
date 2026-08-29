#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x] += 1;
    }

    cout << n - *max_element(freq.begin(), freq.end()) << '\n';
}