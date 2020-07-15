/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 */

// @lc code=start
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));

        int ans(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                dp[i + 1][j + 1][0] = dp[i][j + 1][0] + grid[i][j];
                dp[i + 1][j + 1][1] = dp[i + 1][j][1] + grid[i][j];
            }
        }

        int x(0), y(0), len(0);
        for (len = min(m, n); len > 0; --len) {
            for (i = 0; i + len <= m; ++i) {
                for (j = 0; j + len <= n; ++j) {
                    x = i + len - 1;
                    y = j + len - 1;
                    if (dp[x + 1][j + 1][0] - dp[i][j + 1][0] == len && \
                        dp[x + 1][y + 1][0] - dp[i][y + 1][0] == len && \
                        dp[i + 1][y + 1][1] - dp[i + 1][j][1] == len && \
                        dp[x + 1][y + 1][1] - dp[x + 1][j][1] == len) {
                        return len * len;
                    }
                }
            }
        }


        return 0;
    }
};
// @lc code=end

