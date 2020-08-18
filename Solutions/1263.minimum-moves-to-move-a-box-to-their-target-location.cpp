/*
 * @lc app=leetcode id=1263 lang=cpp
 *
 * [1263] Minimum Moves to Move a Box to Their Target Location
 */

// @lc code=start
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        // const paras
        const vector<vector<int>> dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        const int m(grid.size()), n(grid[0].size());

        // set initial paras
        int begx(0), begy(0), boxx(0), boxy(0), tarx(0), tary(0);
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (grid[i][j] == 'S') {
                    begx = i;
                    begy = j;
                } else if (grid[i][j] == 'B') {
                    boxx = i;
                    boxy = j;
                } else if (grid[i][j] == 'T') {
                    tarx = i;
                    tary = j;
                }
            }
        }

        // reachable check
        auto reachable = [&](int x, int y, int tx, int ty, int bx, int by) -> bool {
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[tx][ty] == '#') { return false; }
            vector<vector<bool>> seen(m, vector<bool>(n, false)); 
            queue<pair<int, int>> q;
            q.push({x, y});
            seen[x][y] = true;
            while (!q.empty()) {
                pair<int, int> tmp(q.front());
                q.pop();
                if (tmp.first == tx && tmp.second == ty) { return true; }
                for (int i(0); i < 4; ++i) {
                    int nx(tmp.first + dir[i][0]), ny(tmp.second + dir[i][1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) { continue; }
                    if (seen[nx][ny] || grid[nx][ny] == '#' || (nx == bx && ny == by)) { continue; }
                    seen[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            return false;
        };

        // main bfs loop
        int ans(0);
        unordered_set<int> visited;
        queue<vector<int>> q;
        visited.insert(getKey(begx, begy, boxx, boxy));
        q.push({begx, begy, boxx, boxy});
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                vector<int> cur(q.front());
                q.pop();
                int cpx(cur[0]), cpy(cur[1]), cbx(cur[2]), cby(cur[3]);
                if (cbx == tarx && cby == tary) { return ans; }
                for (int i(0); i < 4; ++i) {
                    int nbx(cbx + dir[i][0]), nby(cby + dir[i][1]);
                    if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || grid[nbx][nby] == '#') { continue; }
                    int key(getKey(cbx, cby, nbx, nby));
                    if (visited.count(key) > 0) { continue; }
                    if (!reachable(cpx, cpy, cbx - dir[i][0], cby - dir[i][1], cbx, cby)) { continue; }
                    visited.insert(key);
                    q.push({cbx, cby, nbx, nby});
                }
            }
            ++ans;
        }
        return -1;
    }
private:
    inline int getKey(int px, int py, int bx, int by) {
        return ((px * 20 + py) << 10) | (bx * 20 + by);
    }
    int getKey(const vector<int>& v) {
        if (v.size() < 4) { return -1; }
        return getKey(v[0], v[1], v[2], v[3]);
    }
};
// @lc code=end

