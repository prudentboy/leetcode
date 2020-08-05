/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        const int m(grid.size()), n(grid[0].size());
        for (auto& hit : hits) { --grid[hit[0]][hit[1]]; }

        vector<int> parents(m * n), rank(m * n, 1);
        iota(parents.begin(), parents.end(), 0);

        function<int(int)> find = [&](int idx) -> int {
            if (parents[idx] != idx) { parents[idx] = find(parents[idx]); }
            return parents[idx];
        };
        function<void(int, int)> merge = [&](int idx1, int idx2) {
            int p1(find(idx1)), p2(find(idx2));
            if (p1 == p2) { return; }
            if (p1 < p2) {
                rank[p1] += rank[p2];
                rank[p2] = 0;
                parents[p2] = p1;
            } else {
                rank[p2] += rank[p1];
                rank[p1] = 0;
                parents[p1] = p2;
            }
        };

        function<int(void)> cntResBricks = [&]() -> int {
            int ret(0);
            for (int y(0); y < n; ++y) { if (grid[0][y] == 1) { ret += rank[y]; } }
            return ret;
        };

        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (grid[i][j] <= 0) { continue; }
                if (i > 0 && grid[i - 1][j] == 1) { merge(i * n + j, i * n - n + j); }
                if (j > 0 && grid[i][j - 1] == 1) { merge(i * n + j, i * n + j - 1); }
            }
        }

        int pre(cntResBricks());
        vector<int> ans(hits.size());
        int idx(hits.size());
        for (auto it(hits.rbegin()); it != hits.rend(); ++it) {
            int x((*it)[0]), y((*it)[1]);
            if (++grid[x][y] <= 0) {
                ans[--idx] = 0;
                continue;
            }
            if (x > 0 && grid[x - 1][y] == 1) { merge(x * n + y, x * n - n + y); }
            if (x < m - 1 && grid[x + 1][y] == 1) { merge(x * n + y, x * n + n + y); }
            if (y > 0 && grid[x][y - 1] == 1) { merge(x * n + y, x * n + y - 1); }
            if (y < n - 1 && grid[x][y + 1] == 1) { merge(x * n + y, x * n + y + 1); }
            int cur(cntResBricks());
            //cout << cur << ' ' << pre << endl;
            ans[--idx] = cur > pre ? cur - pre - 1 : 0;
            pre = cur;
        }
        return ans;
    }
};
// @lc code=end

