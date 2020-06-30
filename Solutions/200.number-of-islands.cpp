/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans(0);
        if (grid.empty()) return ans;

        vector<vector<bool>> table(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i(0); i < grid.size(); ++i)
        {
            for (int j(0); j < grid[0].size(); ++j)
            {
                if (table[i][j] or grid[i][j] != '1') continue;
                markViewed(grid, table, i, j);
                ++ans;
            }
        }
        return ans;
    }
private:
    void markViewed(const vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    {
        if (i < 0 or i >= table.size() or j < 0 or j >= table[0].size() or table[i][j] or grid[i][j] != '1') return;
        table[i][j] = true;
        markViewed(grid, table, i - 1, j);
        markViewed(grid, table, i + 1, j);
        markViewed(grid, table, i, j - 1);
        markViewed(grid, table, i, j + 1);
    }
};

