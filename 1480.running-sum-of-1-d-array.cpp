/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums);
        for (int i(1); i < nums.size(); ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
// @lc code=end

