#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(string& s, unordered_map<string, int>& pres, int idx, int len, string& start) {
        int n = s.length();
        unordered_map<string, int> temp;
        temp[start] += 1;
        int cnt = 1;
        int words = 0;
        for (auto& p : pres) {
            words += p.second;
        }

        for (int i = idx; i <= n - len; i++) {
            string test = s.substr(i, len);
            if (cnt == words) break;
            if (pres.contains(test)) {
                temp[test] += 1;
                if (temp[test] > pres[test]) break;
                i += len - 1;
                cnt += 1;
            } else {
                break;
            }
        }
        for (auto& p : pres) {
            if (p.second != temp[p.first]) return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> pres;
        int len = words[0].length();
        for (string& str : words) {
            pres[str] += 1;
        }

        vector<int> ans;
        int i = 0;
        int n = s.length();

        while (i <= n - len) {
            string test = s.substr(i, len);
            if (pres.contains(test)) {
                bool good = search(s, pres, i + len, len, test);
                if (good) {
                    ans.push_back(i);
                }
            }
            i += 1;
        }
        
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution sol;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo", "the"};
    auto v = sol.findSubstring(s, words);
    for (int val : v) {
        cout << val << ' ';
    }
}