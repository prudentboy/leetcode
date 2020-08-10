/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const vector<vector<int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
        const int m(grid.size()), n(grid[0].size());
        deque<pair<int, int>> dq;
        vector<bool> visited(m * n, false);
        dq.emplace_back(0, 0);
        while (!dq.empty()) {
            pair<int, int> tmp(dq.front());
            dq.pop_front();
            int x(tmp.first / n), y(tmp.first % n);
            if (x == m - 1 && y == n - 1) { return tmp.second; }
            if (visited[tmp.first]) { continue; }
            visited[tmp.first] = true;
            for (int i(0); i < 4; ++i) {
                int nx(x + dir[i][0]), ny(y + dir[i][1]);
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx * n + ny]) { continue; }
                if (grid[x][y] == i + 1) {
                    dq.emplace_front(nx * n + ny, tmp.second);
                } else {
                    dq.emplace_back(nx * n + ny, tmp.second + 1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

