/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        constexpr int M = 1000000007;

        const int n(group.size());
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(G + 1, vector<int>(P + 1)));
        dp[0][0][0] = 1;
        for (int i(1); i <= n; ++i) {
            for (int j(0); j <= G; ++j) {
                for (int k(0); k <= P; ++k) {
                    int g(group[i - 1]), p(profit[i - 1]);
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j < g) { continue; }
                    dp[i][j][k] += dp[i - 1][j - g][max(0, k - p)];
                    dp[i][j][k] %= M;
                }
            }
        }

        long ans(0);
        for (int i(0); i <= G; ++i) {
            ans += dp[n][i][P];
            ans %= M;
        }
        return ans;
    }
};
// @lc code=end

