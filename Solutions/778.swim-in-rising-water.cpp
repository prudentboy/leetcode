/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n(grid.size());
        if (grid.front().front() == n * n - 1 || grid.back().back() == n * n - 1) { return n * n - 1; }

        const vector<pair<int, int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        auto check = [&](int t) -> bool {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            visited[0][0] = true; 
            pair<int, int> tmp;
            queue<pair<int, int>> q;
            q.push({0, 0});
            int nx(0), ny(0);
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                if (tmp.first == n - 1 && tmp.second == n - 1) { return true; }
                for (int i(0); i < 4; ++i) {
                    nx = tmp.first + dir[i].first;
                    ny = tmp.second + dir[i].second;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || grid[nx][ny] > t) { continue; }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            return false;
        };

        int left(0), mid(0), right(n * n - 1);
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return max(left, grid.front().front());
    }
};
// @lc code=end

