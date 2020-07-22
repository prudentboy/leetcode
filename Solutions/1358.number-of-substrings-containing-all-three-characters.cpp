/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans(0);
        int i(0), j(0), n(s.size());
        vector<int> cnts(3, 0);
        for (i = 0; i < n; ++i) {
            ++cnts[s[i] - 'a'];
            while (cnts[0] > 0 && cnts[1] > 0 && cnts[2] > 0) {
                ans += n - i;
                --cnts[s[j++] - 'a'];
            }
        }
        return ans;
    }
};
// @lc code=end

