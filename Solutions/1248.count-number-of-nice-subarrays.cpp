/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans(0);

        int n(nums.size());
        vector<int> oddCnts(n + 1);
        oddCnts[0] = 1;

        int sum(0);
        for (int i(0); i < n; ++i) {
            sum += nums[i] & 1;
            if (sum >= k) { ans += oddCnts[sum - k]; }
            ++oddCnts[sum];
        }

        return ans;
    }
};
// @lc code=end

