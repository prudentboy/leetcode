/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        int i(0);
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[2][0] = INT_MIN;
        //cout << i << ": " << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << endl;

        for (i = 1; i < prices.size(); ++i)
        {
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
            dp[2][i] = dp[1][i - 1] + prices[i];
            //cout << i << ": " << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << endl;
        }

        return max(dp[2][i - 1], dp[0][i - 1]);
    }
};

