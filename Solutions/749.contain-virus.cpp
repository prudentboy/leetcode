/*
 * @lc app=leetcode id=749 lang=cpp
 *
 * [749] Contain Virus
 */

// @lc code=start
class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        // const para
        const int m(grid.size()), n(grid[0].size());
        const vector<vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        
        // reference paras
        int w(0);
        vector<bool> visited(m * n);
        unordered_set<int> active, danger;
        // search map func, return 1.active area set, 2.danger area set, 3.wall cnt needed
        function<void(int, int)> bfs = [&](int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2) { return; }
            if (grid[x][y] == 0) {
                ++w;
                danger.insert(x * n + y);
                return;
            }
            if (visited[x * n + y]) { return; }
            active.insert(x * n + y);
            visited[x * n + y] = true;
            for (const auto& dir : dirs) { bfs(x + dir[0], y + dir[1]); }
        };

        // main loop
        int ans(0);
        while (true) {
            fill(visited.begin(), visited.end(), false);
            vector<unordered_set<int>> dangers;
            unordered_set<int> ctrl;
            int wall(0), idx(0), mn(0);
            // search contaminated areas
            for (int i(0); i < m; ++i) {
                for (int j(0); j < n; ++j) {
                    if (grid[i][j] != 1 || visited[i * n + j]) { continue; }
                    w = 0;
                    active.clear();
                    bfs(i, j);
                    if (danger.empty()) { continue; }
                    dangers.emplace_back(move(danger));
                    if (dangers.back().size() > mn) {
                        wall = w;
                        idx = dangers.size() - 1;
                        mn = dangers[idx].size();
                        swap(ctrl, active);
                    }
                }
            }

            // end of loop
            if (dangers.empty()) { break; }

            // add walls
            ans += wall;

            // update map
            for (auto pos : ctrl) { grid[pos / n][pos % n] = 2; }
            for (int i(0); i < dangers.size(); ++i) {
                if (i == idx) { continue; }
                for (auto nxt : dangers[i]) { grid[nxt / n][nxt % n] = 1; }
            }
        }
        return ans;
    }
};
// @lc code=end

