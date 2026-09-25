#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i & 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
        a[i] = x;
    }
    vector<int> ans(n);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    sort(a.begin(), a.end());


    int l = 0;
    int r = n - 1;
    int oddptr = 0;
    int evenptr = 0;
    int aptr = 0;
    int need = a[aptr];

    while (l < r) {
        if (oddptr < int(odd.size()) && odd[oddptr] == need) {
            if (l % 2 == 0 && r % 2 == 0) {
                cout << "NO" << '\n';
                return;
            }
            if (l % 2) {
                l += 1;
            } else {
                r -= 1;
            }
            oddptr += 1;
        } else if (evenptr < int(even.size()) && even[evenptr] == need) {
            if (l % 2 != 0 && r % 2 != 0) {
                cout << "NO" << '\n';
                return;
            }
            if (l % 2 == 0) {
                l += 1;
            } else {
                r -= 1;
            }
            evenptr += 1;
        } else {
            cout << "NO" << '\n';
            return;
        }
        aptr += 1;
        need = a[aptr];
    }
    cout << "YES" << '\n';
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