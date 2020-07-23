/*
 * @lc app=leetcode id=1391 lang=cpp
 *
 * [1391] Check if There is a Valid Path in a Grid
 */

// @lc code=start
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());
        // direct : 0-left, 1-right, 2-up, 3-down
        unordered_map<int, set<int>> rule({{1, {1, 3, 5}}, {11, {1, 4, 6}}, {22, {2, 5, 6}}, {32, {2, 3, 4}}, \
                                           {3, {2, 5, 6}}, {33, {1, 4, 6}}, {34, {5, 3, 1}}, {14, {2, 5, 6}}, \
                                           {5, {2, 3, 4}}, {25, {1, 4, 6}}, {26, {3, 5, 1}}, {16, {2, 3, 4}}});
        unordered_map<int, pair<int, int>> next({{1, {0, 1}}, {11, {0, -1}}, {22, {1, 0}}, {32, {-1, 0}}, \
                                                 {3, {1, 0}}, {33, {0, -1}}, {34, {0, 1}}, {14, {1, 0}}, \
                                                 {5, {-1, 0}}, {25, {0, -1}}, {26, {0, 1}}, {16, {-1, 0}}});
        unordered_map<int, int> direct({{1, 0}, {11, 10}, {22, 20}, {32, 30}, {3, 20}, {33, 10}, {34, 0}, {14, 20}, {5, 30}, {25, 10}, {26, 0}, {16, 30}});

        vector<int> start({-1, 1, 22, 3, 14, -1, 26});
        int x(0), y(0);
        int cur(start[grid[x][y]]);
        if (cur == -1) { return false; }
        
        auto check = [&]() -> bool {
            int cnt(0);
            while (cnt++ < m * n) {
                if (x == m - 1 && y == n - 1) { return true; }
                x += next[cur].first;
                y += next[cur].second;
                if (x < 0 || x >= m || y < 0 || y >= n || rule[cur].count(grid[x][y]) == 0) { return false; }
                cur = direct[cur] + grid[x][y];
            }
            return false;
        };
        if (check()) { return true; }
        if (grid[0][0] == 4) {
            cur = 34;
            x = y = 0;
            return check();
        }
        return false;
    }
};
// @lc code=end

