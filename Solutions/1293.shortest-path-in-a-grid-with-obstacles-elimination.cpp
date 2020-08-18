/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const vector<vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        const int m(grid.size()), n(grid[0].size());

        vector<vector<int>> seen(m, vector<int>(n, 10000));
        //unordered_set<int> visited;
        auto getKey = [](int x, int y, int cnt) { return (cnt << 12) | (x << 6) | (y << 6); };
        queue<vector<int>> q;
        q.push({0, 0, 0});
        seen[0][0] = 0;
        //visited.insert(getKey(0, 0, 0));

        int ans(0);
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                vector<int> cur(q.front());
                q.pop();
                int cx(cur[0]), cy(cur[1]), cCnt(cur[2]);
                //cout << "cur: " << cx << ' ' << cy << ' ' << cCnt << endl;
                if (cx == m - 1 && cy == n - 1) { return ans; }
                for (auto& dir : dirs) {
                    int nx(cx + dir[0]), ny(cy + dir[1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) { continue; }
                    int nCnt(cCnt + grid[nx][ny]);
                    if (nCnt > k || nCnt >= seen[nx][ny]) { continue; }
                    //cout << nx << ' ' << ny << ' ' << nCnt << endl;
                    seen[nx][ny] = nCnt;
                    //visited.insert(getKey(nx, ny, nCnt));
                    q.push({nx, ny, nCnt});
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

