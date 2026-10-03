#include <bits/stdc++.h>
using namespace std;

vector<int> good;
void pre() {
    for (int i = 1; i <= 9; i++) {
        int res = 0;
        for (int j = i; j <= 9; j++) {
            res = (10 * res) + j;
            good.push_back(res);
        } 
    }
}

void solve() {
    int n;
    cin >> n;

    int l = 0;
    int r = int(good.size()) - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (good[mid] >= n) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (res == -1) {
        cout << -1 << '\n';
    } else {
        cout << good[res] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    pre();
    sort(good.begin(), good.end());
    while (t--) {
        solve();
    }
    return 0;
}