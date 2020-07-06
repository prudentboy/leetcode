/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m(A.size()), n(B.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int i(0), j(0);
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

