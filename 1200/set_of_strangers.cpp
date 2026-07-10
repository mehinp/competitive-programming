#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& grid, int i, int j) {
    if (i + 1 < grid.size()) {
        if (grid[i][j] == grid[i + 1][j]) {
            return true;
        }
    }
    if (j + 1 < grid[0].size()) {
        if (grid[i][j] == grid[i][j + 1]) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(a[i][j], mx);
        }
    }

    vector<int> num(mx + 1);
    bool isTwo = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(a, i, j)) {
                num[a[i][j]] = 2;
                isTwo = true;
            } else if (num[a[i][j]] != 2) {
                num[a[i][j]] = 1;
            }
        }
    }

  
    cout << (accumulate(num.begin(), num.end(), 0) - (isTwo ? 2 : 1)) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}