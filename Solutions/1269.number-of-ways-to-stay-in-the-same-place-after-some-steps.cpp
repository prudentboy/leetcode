/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution {
public:
    int numWays(int steps, int arrLen) {
        constexpr int M = 1000000007;
        arrLen = min(arrLen, steps + 1);
        vector<vector<long>> dp(steps + 1, vector<long>(arrLen));
        dp[0][0] = 1;
        for (int i(1); i <= steps; ++i) {
            for (int j(0); j < arrLen; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) { dp[i][j] += dp[i - 1][j - 1]; }
                if (j < arrLen - 1) { dp[i][j] += dp[i - 1][j + 1]; }
                dp[i][j] %= M;
            }
        }
        return dp[steps][0];
    }
};
// @lc code=end

