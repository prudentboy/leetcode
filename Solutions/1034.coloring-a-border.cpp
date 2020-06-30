/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m(grid.size()), n(grid[0].size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> border;
        queue<pair<int, int>> q;
        q.push({r0, c0});
        visited[r0][c0] = true;
        if (isborder(grid, r0, c0)) { border.push_back({r0, c0}); }
        pair<int, int> tmp;
        int len(0), nx(0), ny(0);
        const vector<vector<int>> direct({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                if (isborder(grid, tmp.first, tmp.second)) { border.push_back({tmp.first, tmp.second}); }
                for (auto& dir : direct) {
                    nx = tmp.first + dir[0];
                    ny = tmp.second + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) { continue; }
                    if (visited[nx][ny]) { continue; }
                    if (grid[nx][ny] != grid[tmp.first][tmp.second]) { continue; }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        for (auto& p : border) {
            grid[p[0]][p[1]] = color;
        }
        return grid;
    }
private:
    bool isborder(const vector<vector<int>>& grid, int x, int y) {
        int m(grid.size()), n(grid[0].size()), c(grid[x][y]);
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) { return true; }
        if (grid[x - 1][y] != c || grid[x + 1][y] != c) { return true; }
        if (grid[x][y - 1] != c || grid[x][y + 1] != c) { return true; }
        return false;
    }
};
// @lc code=end

