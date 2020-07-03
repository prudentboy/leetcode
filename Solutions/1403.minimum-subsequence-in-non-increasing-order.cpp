/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        int now(0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(nums[i]);
            now += nums[i];
            if (now > sum - now) { return ans; }
        }
        return ans;
    }
};
// @lc code=end

