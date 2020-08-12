/*
 * @lc app=leetcode id=1330 lang=cpp
 *
 * [1330] Reverse Subarray To Maximize Array Value
 */

// @lc code=start
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int ans(0);
        int cur(0), endpoint(0), mx(INT_MIN), mn(INT_MAX);
        for (int i(0); i < nums.size() - 1; ++i) {
            cur = abs(nums[i] - nums[i + 1]);
            endpoint = max(endpoint, abs(nums.front() - nums[i + 1]) - cur);
            endpoint = max(endpoint, abs(nums.back() - nums[i]) - cur);
            mx = max(mx, min(nums[i], nums[i + 1]));
            mn = min(mn, max(nums[i], nums[i + 1]));
            ans += cur;
        }
        return ans + max(endpoint, (mx - mn) * 2);
    }
};
// @lc code=end

