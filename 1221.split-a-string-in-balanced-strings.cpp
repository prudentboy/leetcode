/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans(0);
        int cnt(0);
        for (char c : s) {
            if (c == 'L') {
                --cnt;
            } else {
                ++cnt;
            }
            if (cnt == 0) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

