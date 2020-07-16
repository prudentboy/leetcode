/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());

        int i(0), j(0);
        vector<vector<int>> begs;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] > 0) { begs.push_back({i, j}); }
            }
        }

        int ans(0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        function<void(int x, int y, int s)> dfs = [&](int x, int y, int s) {
            s += grid[x][y];
            ans = max(ans, s);
            for (int i(0); i < 4; ++i) {
                int nx(x + dir[i][0]), ny(y + dir[i][1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0 || visited[nx][ny]) { continue; }
                visited[nx][ny] = true;
                dfs(nx, ny, s);
                visited[nx][ny] = false;
            }
        };

        for (auto& beg : begs) {
            visited[beg[0]][beg[1]] = true;
            dfs(beg[0], beg[1], 0);
            visited[beg[0]][beg[1]] = false;
        }

        return ans;
    }
};
// @lc code=end

