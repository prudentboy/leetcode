/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));
        dp[0][0] = poured;
        int i(0), j(0);
        for (i = 0; i < query_row; ++i)
        {
            for (j = 0; j <= i; ++j)
            {
                if (dp[i][j] > 1)
                {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
                }
            }
        }
        return dp[query_row][query_glass] > 1 ? 1.0 : dp[query_row][query_glass];
    }
};
// @lc code=end

