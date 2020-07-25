/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 10000000)));

        int x(0), y(0), z(0);
        for (z = 0; z <= n; ++z) { dp[0][0][z] = 0; }

        for (x = 1; x <= target; ++x) {
            for (y = x; y <= m; ++y) {
                int beg(1), end(n), cst(0);
                if (houses[y - 1] > 0) { beg = end = houses[y - 1]; }
                for (z = beg; z <= end; ++z) {
                    if (houses[y - 1] != z) { cst = cost[y - 1][z - 1]; }
                    for (int pz(1); pz <= n; ++pz) {
                        int candidate((pz == z ? dp[x][y - 1][z] : dp[x - 1][y - 1][pz]) + cst);
                        dp[x][y][z] = min(dp[x][y][z], candidate);
                    }
                }
            }
        }

        int ans(INT_MAX);
        for (z = 1; z <= n; ++z) { ans = min(ans, dp[target][m][z]); }

        return ans >= 10000000 ? -1 : ans;
    }
};
// @lc code=end

