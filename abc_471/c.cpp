#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    long long ans = 0;
    int pos = 0;
    while (!ms.empty()) {
        auto it = ms.lower_bound(pos);
        if (it == ms.end()) it--;
        int dist = abs(pos - *it);
        if (it != ms.begin() && abs(pos - *prev(it)) <= dist) {      
            ans += abs(pos - *prev(it));
            pos = *prev(it);
            ms.erase(prev(it));
        } else {
            ans += dist;
            pos = *it;
            ms.erase(it);
        }
    }
    cout << ans << '\n';
}