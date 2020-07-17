/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 */

// @lc code=start
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        constexpr int M(1000000007);
        
        long long int ans(0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(16)));

        int i(0);
        for (i = 0; i < 6; ++i) { dp[1][i][1] = 1; }

        int j(0), k(0), l(0);
        for (i = 2; i <= n; ++i) {
            for (j = 0; j < 6; ++j) {
                for (k = 0; k < 6; ++k) {
                    if (j != k) {
                        for (l = 1; l <= rollMax[k]; ++l) {
                            if (dp[i - 1][k][l] == 0) { break; }
                            dp[i][j][1] += dp[i - 1][k][l];
                            if (dp[i][j][1] >= M) { dp[i][j][1] -= M; }
                        }
                    } else {
                        for (l = 1; l < rollMax[k]; ++l) {
                            if (dp[i - 1][j][l] == 0) { break; }
                            dp[i][j][l + 1] = dp[i - 1][j][l];
                            //if (dp[i][j][l + 1] >= M) { dp[i][j][l + 1] -= M; }
                        }
                    }
                }
            }
        }

        for (i = 0; i < 6; ++i) {
            for (j = 1; j <= rollMax[i]; ++j) {
                ans += dp[n][i][j];
                if (ans >= M) { ans -= M; }
            }
        }
        
        return ans;
    }
};
// @lc code=end

