/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2, 0);
        if (b < a) { swap(a, b); }
        if (c < a) { swap(a, c); }
        if (c < b) { swap(b, c); }
        ans[1] = c - a - 2;
        if (b - a == 1 && c - b == 1) {
            ans[0] = 0;
        } else if (b - a <= 2 || c - b <= 2) {
            ans[0] = 1;
        } else {
            ans[0] = 2;
        }
        return ans;
    }
};
// @lc code=end

