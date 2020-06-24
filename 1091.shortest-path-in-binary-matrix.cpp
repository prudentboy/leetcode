/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n(grid.size());
        if (grid[0][0] != 0) { return -1; }
        const vector<vector<int>> direct({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int level(1), len(0);
        queue<pair<int, int>> q;
        pair<int, int> tmp;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                if (tmp.first == n - 1 && tmp.second == n - 1) { return level; }
                for (int i(0); i < 8; ++i) {
                    int nextX(tmp.first + direct[i][0]), nextY(tmp.second + direct[i][1]);
                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) { continue; }
                    if (visited[nextX][nextY] || grid[nextX][nextY] == 1) { continue; }
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
            ++level;
        }
        return -1;
    }
};
// @lc code=end

