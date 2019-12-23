/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int i(0), j(0), m(A.size()), n(A[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (j = 0; j < n; ++j) { dp[0][j] = A[0][j]; }
        for (i = 1; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                int mn = A[i][j] + dp[i - 1][j];
                if (j > 0) { mn = min(mn, A[i][j] + dp[i - 1][j - 1]); }
                if (j < n - 1) { mn = min(mn, A[i][j] + dp[i - 1][j + 1]); }
                dp[i][j] = mn;
            }
        }
        int ans(dp[m - 1][0]);
        for (j = 1; j < n; ++j) { ans = min(ans, dp[m - 1][j]); }
        return ans;
    }
};
// @lc code=end

