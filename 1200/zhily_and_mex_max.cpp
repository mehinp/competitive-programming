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
    vector<int> nums;
    nums.push_back(*max_element(a.begin(), a.end()));
    for (int i = 0; i < n; i++) {
        if (a[i] == nums[0]) continue;
        if (a[i] != nums.back()) {
            nums.push_back(a[i]);
        }
    }


    int mex = nums[0] == 0 ? 1 : 0;
    long long sum = nums[0] + mex;
    set<int> seen;
    seen.insert(nums[0]);
    for (int i = 1; i < int(nums.size()); i++) {
        seen.insert(nums[i]);
        while (seen.contains(mex)) {
            mex++;
        }
        sum += nums[0] + mex;
    }
    cout << sum + 1LL * (nums[0] + mex) * (a.size() - nums.size()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}