/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n(nums.size());
        deque<int> dq;
        vector<int> dp(n, INT_MIN);
        dq.push_back(0);
        dp[0] = nums.front();
        int ans(INT_MIN);
        for (int i(1); i < n; ++i) {
            if (i > k && i - dq.front() > k) { dq.pop_front(); }
            dp[i] = max(0, dp[dq.front()]) + nums[i];
            while (!dq.empty() && dp[dq.back()] < dp[i]) { dq.pop_back(); }
            dq.push_back(i);
            ans = max(ans, dp[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end

