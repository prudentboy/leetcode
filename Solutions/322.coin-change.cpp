/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i(1); i < amount + 1; ++i)
        {
            for (int c : coins)
            {
                if (c <= i && dp[i] > dp[i - c] + 1) dp[i] = dp[i - c] + 1;
            }
            //cout << i << ": " << dp[i] << endl;
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

