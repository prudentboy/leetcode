/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 */

// @lc code=start
class Solution {
public:
    int numPermsDISequence(string S) {
        constexpr int M = 1000000007;
        
        int n(S.size());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;

        int i(0), j(0), k(0);
        for (i = 1; i <= n; ++i) {
            for (j = 0; j <= i; ++j) {
                if (S[i - 1] == 'D') {
                    for (k = j; k <= n; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= M;
                    }
                } else {
                    for (k = 0; k < j; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= M;
                    }
                }
            }
        }

        int ans(0);
        for (i = 0; i <= n; ++i) {
            ans += dp[n][i];
            ans %= M;
        }
        return ans;
    }
};
// @lc code=end

