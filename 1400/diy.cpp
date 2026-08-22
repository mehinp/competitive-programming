#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<int> blocks;
    for (int i = 1; i < n; i += 2) {
        if (a[i] == a[i - 1]) {
            blocks.push_back(a[i]);
        } else {
            i -= 1;
        }
    }
    if (int(blocks.size()) < 4) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        int m = blocks.size();
        cout << blocks[0] << ' ' << blocks[1] << ' ';
        cout << blocks[0] << ' ' << blocks[m - 1] << ' ';
        cout << blocks[m - 2] << ' ' << blocks[1] << ' ';
        cout << blocks[m - 2] << ' ' << blocks[m - 1] << ' ';
        cout << '\n';
    }

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