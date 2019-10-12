/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        if (n <= 3) return n - 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        int i(0), j(0), k(0);
        for (i = 1; i <= n; ++i) dp[i][i] = 0;
        for (i = n; i > 0; --i)
        {
            if (i - 1 > 0) dp[i - 1][i] = i - 1;
            if (i - 2 > 0) dp[i - 2][i] = i - 1;
        }

        for (j = 3; n - j > 0; ++j)
        {
            for (i = n; i - j > 0; --i)
            {
                for (k = i - j + 1; k < i; ++k)
                { 
                    dp[i - j][i] = min(dp[i - j][i], k + max(dp[i - j][k - 1], dp[k + 1][i]));
                    //cout << i - j << ' ' << i << ' ' << k << ' ' << dp[i - j][i] << endl;
                }
            }
        }
        /*
        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        */
        return dp[1][n];
    }
};
// @lc code=end

