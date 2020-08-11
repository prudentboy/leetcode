/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());
        const vector<vector<int>> dir({{1, -1, 1, -1}, {1, -1, 1, 0}, {1, -1, 1, 1}, {1, 0, 1, -1}, {1, 0, 1, 0}, {1, 0, 1, 1}, {1, 1, 1, -1}, {1, 1, 1, 0}, {1, 1, 1, 1}});
        vector<vector<vector<vector<int>>>> memo(m, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, -1))));
        function<int(int, int, int, int)> dp = [&](int x1, int y1, int x2, int y2) {
            if (x1 >= m || x2 >= m || y1 < 0 || y1 >= n || y2 < 0 || y2 >= n) { return 0; }
            if (memo[x1][y1][x2][y2] != -1) { return memo[x1][y1][x2][y2]; }
            int ret(0);
            for (int i(0); i < 9; ++i) { ret = max(ret, dp(x1 + dir[i][0], y1 + dir[i][1], x2 + dir[i][2], y2 + dir[i][3])); }
            ret += grid[x1][y1];
            if (y1 != y2) { ret += grid[x2][y2]; }
            return memo[x1][y1][x2][y2] = ret;
        };

        return dp(0, 0, 0, n - 1);
    }
};
// @lc code=end

