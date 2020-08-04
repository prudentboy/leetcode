/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m(grid.size()), n(grid[0].size());
        int sx(0), sy(0), finalState(0);
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') { finalState |= 1 << (grid[i][j] - 'a'); }
            }
        }

        const vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        queue<int> q;
        unordered_set<int> visited;
        q.push(getQueueMember(sx, sy, 0));
        visited.insert(getQueueMember(sx, sy, 0));
        int ans(0), x(0), y(0), state(0);
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                int tmp(q.front());
                q.pop();
                getPosNState(tmp, x, y, state);
                if (state == finalState) { return ans; }
                for (int i(0); i < 4; ++i) {
                    int nx(x + dir[i][0]), ny(y + dir[i][1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') { continue; }
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && (state & (1 << (grid[nx][ny] - 'A'))) == 0) { continue; }
                    int nstate(state);
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') { nstate |= 1 << (grid[nx][ny] - 'a'); }
                    int key(getQueueMember(nx, ny, nstate));
                    if (visited.count(key) > 0) { continue; }
                    q.push(key);
                    visited.insert(key);
                }
            }
            ++ans;
        }

        return -1;
    }
private:
    inline int getQueueMember(int x, int y, int state) {
        // queue member: 0-6 state, 7-12 x, 13-18 y
        return (y << 12) | (x << 6) | state;
    }
    inline void getPosNState(int queueMember, int& x, int& y, int& state) {
        state = queueMember & 0b111111;
        x = (queueMember & 0b111111000000) >> 6;
        y = queueMember >> 12;
    }
};
// @lc code=end

