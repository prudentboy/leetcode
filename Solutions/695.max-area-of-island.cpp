/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int ans(0);
        int m(grid.size()), n(grid[0].size());
        int i(0), j(0), cnt(0);
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0 || flag[i][j]) continue;
                cnt = 0;
                helper(grid, flag, i, j, cnt);
                if (cnt > ans) ans = cnt;
            }
        }

        return ans;
    }
private:
    void helper(const vector<vector<int>>& grid, vector<vector<bool>>& flag, int i, int j, int& cnt)
    {
        int m(grid.size()), n(grid[0].size());
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || flag[i][j]) return;
        ++cnt;
        flag[i][j] = true;
        helper(grid, flag, i - 1, j, cnt);
        helper(grid, flag, i + 1, j, cnt);
        helper(grid, flag, i, j - 1, cnt);
        helper(grid, flag, i, j + 1, cnt);
    }
};
// @lc code=end

