/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum(0), ans(0), n(nums.size());
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i(0); i < n; ++i)
        {
            sum += nums[i];
            ans += m[sum - k];
            ++m[sum];
        }
        return ans;
    }
};
// @lc code=end

