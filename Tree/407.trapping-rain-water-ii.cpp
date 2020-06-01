/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m(heightMap.size()), n(heightMap[0].size());
        if (m < 3 || n < 3) { return 0; }
        
        const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        using TDPoint = pair<int, pair<int, int>>;
        priority_queue<TDPoint, vector<TDPoint>, greater<TDPoint>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans(0);
        
        // init queue and flag map
        int i(0), j(0);
        i = 0;
        for (j = 0; j < n; ++j) {
            q.push({heightMap[i][j], {i, j}});
            visited[i][j] = true;
        }
        i = m - 1;
        for (j = 0; j < n; ++j) {
            q.push({heightMap[i][j], {i, j}});
            visited[i][j] = true;
        }
        j = 0;
        for (i = 1; i < m - 1; ++i) {
            q.push({heightMap[i][j], {i, j}});
            visited[i][j] = true;
        }
        j = n - 1;
        for (i = 1; i < m - 1; ++i) {
            q.push({heightMap[i][j], {i, j}});
            visited[i][j] = true;
        }

        int mn(-1), x(0), y(0);
        const int kDirLen = 4;
        TDPoint tmp;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();

            if (tmp.first < mn) { ans += mn - tmp.first; }
            else { mn = tmp.first; }

            for (i = 0; i < kDirLen; ++i) {
                x = tmp.second.first + dir[i].first;
                y = tmp.second.second + dir[i].second;
                if (x < 0 || y < 0 || x >= m || y >= n) { continue; }
                if (visited[x][y]) { continue; }
                q.push({heightMap[x][y], {x, y}});
                visited[x][y] = true;
            }
        }

        return ans;
    }
};
// @lc code=end

