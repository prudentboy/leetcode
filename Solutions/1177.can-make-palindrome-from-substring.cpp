/*
 * @lc app=leetcode id=1177 lang=cpp
 *
 * [1177] Can Make Palindrome from Substring
 */

// @lc code=start
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n(s.size());
        vector<int> prefixTag(n + 1);
        int tag(0), i(0);
        for (i = 0; i < n; ++i) {
            tag ^= (1 << (s[i] - 'a'));
            prefixTag[i + 1] = tag;
        }

        auto calMinSub = [&](int i, int j) -> int {
            int tagDiff(prefixTag[i] ^ prefixTag[j + 1]);
            //cout << tagDiff << endl;
            int cnt(0);
            while (tagDiff > 0) {
                ++cnt;
                tagDiff &= (tagDiff - 1);
            }
            return cnt >> 1;
        };

        int m(queries.size());
        vector<bool> ans(m, false);
        for (i = 0; i < m; ++i) {
            ans[i] = calMinSub(queries[i][0], queries[i][1]) <= queries[i][2];
        }

        return ans;
    }
};
// @lc code=end

