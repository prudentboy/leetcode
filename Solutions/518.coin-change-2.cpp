/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n(coins.size());
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        int i(0), j(0);
        for (i = 0; i <= n; ++i) dp[i][0] = 1;
        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= amount; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end

