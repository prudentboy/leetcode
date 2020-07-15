/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        int i(0), j(0);
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        if (q.size() == 0 || q.size() == m * n) { return -1; }
        
        int ans(0);
        int len(0), x(0), y(0), nx(0), ny(0);
        pair<int, int> tmp;
        const vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        while (!q.empty()) {
            len = q.size();
            //cout << len << ' ' << ans << endl;
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                x = tmp.first;
                y = tmp.second;
                for (i = 0; i < 4; ++i) {
                    nx = x + dir[i][0];
                    ny = y + dir[i][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) { continue; }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            ++ans;
        }
        return --ans;
    }
};
// @lc code=end

