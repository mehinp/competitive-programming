#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> arr(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = arr[i];
    }
    int lastReset = -1;
    vector<int> last(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        if (last[a] < lastReset) {
            ans[a] = arr[a];
        }
        ans[a] += b;
        if (ans[a] > h) {
            lastReset = i;
            ans[a] = arr[a];
        }
        last[a] = i;
    }

    for (int i = 0; i < n; i++) {
        if (last[i] < lastReset) ans[i] = arr[i];
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}