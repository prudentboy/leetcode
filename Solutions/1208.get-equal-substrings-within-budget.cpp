/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans(0);

        int n(s.size());
        int i(0), j(0), cost(0);
        for (i = 0; i < n; ++i) {
            cost += abs(s[i] - t[i]);
            while (cost > maxCost && j <= i) {
                cost -= abs(s[j] - t[j]);
                ++j;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
// @lc code=end

