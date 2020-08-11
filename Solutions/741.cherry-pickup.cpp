/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(m, -2)));

        function<int(int, int, int, int)> dp = [&](int x1, int y1, int x2, int y2) {
            if (x1 >= m || y1 >= n || x2 >= m || y2 >= n || grid[x1][y1] < 0 || grid[x2][y2] < 0) { return -1; }
            if (x1 == m - 1 && y1 == n - 1) { return grid[m - 1][n - 1]; }
            if (memo[x1][y1][x2] != -2) { return memo[x1][y1][x2]; }
            int ret(-1);
            ret = max(max(dp(x1 + 1, y1, x2 + 1, y2), dp(x1 + 1, y1, x2, y2 + 1)), max(dp(x1, y1 + 1, x2 + 1, y2), dp(x1, y1 + 1, x2, y2 + 1)));
            if (ret < 0) { return memo[x1][y1][x2] = -1; }
            ret += grid[x1][y1];
            if (x1 != x2) { ret += grid[x2][y2]; }
            return memo[x1][y1][x2] = ret;
        };

        return max(0, dp(0, 0, 0, 0));
    }
};
// @lc code=end

