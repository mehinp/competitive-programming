#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    vector<int> targets;
    if (mn == 1) {
        targets.push_back(1);
        targets.push_back(2);
    } else {
        while (true) {
            targets.push_back(mn);  
            if (mn == 1) break;
            if (mn & 1) mn++;
            else mn /= 2;
        }
    }

    int ans = INF;
    for (int ta : targets) {
        int cost = 0;
        bool works = true;
        for (int val : a) {
            bool good = false;
            if (val == 1) {
                if (ta == 2) {
                    cost++;
                }
                continue;
            }
            while (true) {
                if (val == ta) {
                    good = true;
                    break;
                }
                if (val == 1) {
                    break;
                }
                if (val & 1) {
                    val++;
                } else {
                    val /= 2;
                }
                cost++;
            }
            if (!good) {
                works = false;
                break;
            }
        }
        if (works) {
            ans = min(ans, cost);
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


