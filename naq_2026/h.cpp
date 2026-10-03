#include <bits/stdc++.h>
using namespace std;
#include <random>

char Ask(char answer) {
    cout << answer << '\n';
    cout.flush();
    char res;
    if (!(cin >> res)) {
        exit(0);
    }
    return res;
}


void solve() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0, 1);
    for (int i = 0; i < 100; i++) {
        int random = dist(gen);
        char which;
        if (random == 0) {
            which = 'F';
        } else {
            which = 'T';
        }
        char res = Ask(which);
        if (res == 'T') {
            which = 'F';
        } else {
            which = 'T';
        }
        Ask(which);
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