/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n(rods.size());
        int sum(accumulate(rods.begin(), rods.end(), 0));
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        dp[0][0] = 0;        

        int i(0), j(0);
        for (i = 1; i <= n; ++i) {
            for (j = 0; j + rods[i - 1] <= sum; ++j) {
                if (dp[i - 1][j] < 0) { continue; }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j + rods[i - 1]] = max(dp[i][j + rods[i - 1]], dp[i - 1][j]);
                dp[i][abs(j - rods[i - 1])] = max(dp[i][abs(j - rods[i - 1])], dp[i - 1][j] + min(rods[i - 1], j));
            }
        }

        return dp[n][0];
    }
};
// @lc code=end

