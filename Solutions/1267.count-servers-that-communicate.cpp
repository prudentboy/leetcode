/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        vector<int> rows(m), cols(n);
        int ans(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { continue; }
                ++rows[i];
                ++cols[j];
                ++ans;
            }
        }

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { continue; }
                if (rows[i] == 1 && cols[j] == 1) { --ans; }
            }
        }

        return ans;
    }
};
// @lc code=end

