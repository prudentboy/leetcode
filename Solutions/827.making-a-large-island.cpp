/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());

        int cnt(0);
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) { cnt += grid[i][j]; }
        }
        if (cnt == 0) { return 1; }
        if (cnt == 1) { return min(2, m * n); }
        if (cnt >= m * n - 1) { return m * n; }

        int groupId(1);
        vector<vector<int>> groupMark(m, vector<int>(n));
        vector<int> groupSize(1);

        const vector<vector<int>> dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        auto bfs = [&](int x, int y) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            visited[x][y] = true;
            groupMark[x][y] = groupId;
            q.push({x, y});
            int cnt(0);
            pair<int, int> tmp;
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                ++cnt;
                for (int i(0); i < 4; ++i) {
                    int nx(tmp.first + dir[i][0]);
                    int ny(tmp.second + dir[i][1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1 || visited[nx][ny]) { continue; }
                    visited[nx][ny] = true;
                    groupMark[nx][ny] = groupId;
                    q.push({nx, ny});
                }
            }
            ++groupId;
            groupSize.push_back(cnt);
        };

        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (grid[i][j] == 0 || groupMark[i][j] > 0) { continue; }
                bfs(i, j);
            }
        }

        int ans(0);
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (grid[i][j] == 1) { continue; }
                int cur(1);

                vector<int> seen;
                auto check = [&](int id) {
                    for (int se : seen) { if (se == id)  {return true;} }
                    return false;
                };

                if (i > 0 && !check(groupMark[i - 1][j])) {
                    cur += groupSize[groupMark[i - 1][j]];
                    seen.push_back(groupMark[i - 1][j]);
                }
                if (i < m - 1 && !check(groupMark[i + 1][j])) {
                    cur += groupSize[groupMark[i + 1][j]];
                    seen.push_back(groupMark[i + 1][j]);
                }
                if (j > 0 && !check(groupMark[i][j - 1])) {
                    cur += groupSize[groupMark[i][j - 1]];
                    seen.push_back(groupMark[i][j - 1]);
                }
                if (j < n - 1 && !check(groupMark[i][j + 1])) { cur += groupSize[groupMark[i][j + 1]]; }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
// @lc code=end

