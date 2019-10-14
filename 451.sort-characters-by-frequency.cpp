/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        if (s.size() < 3) return s;

        string ans(s.size(), 0);

        unordered_map<char, int> m;
        vector<vector<char>> v(s.size() + 1);

        for (char c : s) ++m[c];
        for (auto& p : m) v[p.second].push_back(p.first);

        int i(0), j(0), k(0);
        for (i = v.size() - 1; i >= 0; --i)
        {
            if (v[i].empty()) continue;
            for (char c : v[i])
            {
                j = i;
                while (j-- > 0) ans[k++] = c;
            }
        }

        return ans;
    }
};
// @lc code=end

