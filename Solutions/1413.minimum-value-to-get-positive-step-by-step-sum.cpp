/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn(0), sm(0);
        for (int n : nums) {
            sm += n;
            mn = min(mn, sm);
        }
        return 1 - mn;
    }
};
// @lc code=end

