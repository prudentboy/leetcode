/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        int zeroCnt(0);
        int startX(0), startY(0), endX(0), endY(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { ++zeroCnt; }
                else if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }

        int ans(0);
        const vector<vector<int>> direct({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[startX][startY] = true;
        std::function<void(int, int, int, int&)> dfs;
        dfs = [&](int x, int y, int cnt, int& ans) {
            //cout << x << ' ' << y << ' ' << cnt << ' ' << ans << endl;
            if (grid[x][y] == 2) {
                if (cnt == zeroCnt) { ++ans; }
                return;
            }
            if (grid[x][y] == 0) { ++cnt; }
            for (int k = 0; k < 4; ++k) {
                int nextX = x + direct[k][0];
                int nextY = y + direct[k][1];
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) { continue; }
                //cout << nextX << ',' << nextY << endl;
                if (visited[nextX][nextY]) { continue; }
                if (grid[nextX][nextY] == 1 || grid[nextX][nextY] == -1) { continue; }
                visited[nextX][nextY] = true;
                dfs(nextX, nextY, cnt, ans);
                visited[nextX][nextY] = false;
            }
        };
        dfs(startX, startY, 0, ans);

        return ans;
    }
};
// @lc code=end

