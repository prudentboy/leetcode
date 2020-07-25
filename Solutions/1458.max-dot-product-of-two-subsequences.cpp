/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m(nums1.size()), n(nums2.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));

        int i(0), j(0);
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]);
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

