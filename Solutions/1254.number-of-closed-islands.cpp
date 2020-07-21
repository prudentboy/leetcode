/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());

        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x > m - 1 || y < 0 || y > n - 1) { return 0; }
            if (grid[x][y] == 1) { return 1; }
            grid[x][y] = 1;
            return dfs(x - 1, y) & dfs(x + 1, y) & dfs(x, y - 1) & dfs(x, y + 1);
        };

        int ans(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) { continue; }
                ans += dfs(i, j);
                //cout << i << ' ' << j << ' ' << ans << endl;
            }
        }

        return ans;
    }
};
// @lc code=end

