    #include <bits/stdc++.h>
    using namespace std;

    void solve() {
        int n, m;
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        vector<int> b(m), c(m);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            min_heap.push(x);
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }

        vector<pair<int, int>> bc;
        vector<int> zeros;
        for (int i = 0; i < m; i++) {
            if (c[i] != 0) {
                bc.emplace_back(b[i], c[i]);
            } else {
                zeros.push_back(b[i]);
            }
        }
        sort(bc.begin(), bc.end());
        int k = bc.size();
        int ans = 0;
        vector<int> remaining;
        for (int i = 0; i < k; i++) {
            while (!min_heap.empty() && min_heap.top() < bc[i].first) {
                remaining.push_back(min_heap.top());
                min_heap.pop();
            }
            if (min_heap.empty()) break;
            ans += 1;
            if (bc[i].second > min_heap.top()) {
                min_heap.pop();
                min_heap.push(bc[i].second);
            }
        }

        while (!min_heap.empty()) {
            remaining.push_back(min_heap.top());
            min_heap.pop();
        }

        sort(remaining.begin(), remaining.end());
        sort(zeros.begin(), zeros.end());
        int j = 0;
        for (int i = 0; i < int(zeros.size()); i++) {
            while (j < int(remaining.size()) && remaining[j] < zeros[i]) {
                j += 1;
            }
            if (j < int(remaining.size())) {
                ans += 1;
                j += 1;
            }
        }
        cout << ans << '\n';
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


