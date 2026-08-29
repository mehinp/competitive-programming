#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char& c : s) {
            c = tolower(c);
        }
        freq[s] += 1;
    }
    int ans = 0;
    for (auto& p : freq) {
        ans = max(ans, p.second);
    }
    cout << ans << '\n';
}