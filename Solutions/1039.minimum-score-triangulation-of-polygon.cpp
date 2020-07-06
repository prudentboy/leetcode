/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n(A.size());

        vector<vector<int>> dp(n, vector<int>(n));
        int i(0), j(0), k(0), l(3);
        for (l = 3; l <= n; ++l) {
            for (i = 0; i + l <= n; ++i) {
                j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

