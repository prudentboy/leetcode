/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return 0;
        int ans(0);
        int i(0), j(0);
        int m(A.size()), n(B.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (i = 1; i < m + 1; ++i)
        {
            for (j = 1; j < n + 1; ++j)
            {
                if (A[i - 1] == B[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

