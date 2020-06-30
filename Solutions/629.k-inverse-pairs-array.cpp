/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution {
public:
    int kInversePairs(int n, int k) {
        const int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        int i(0), j(0);
        for (i = 0; i <= n; ++i) { dp[i][0] = 1; }

        for (i = 1; i < n + 1; ++i) {
            for (j = 1; j < k + 1; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + M) % M;
                }
                cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

