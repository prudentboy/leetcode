/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans(0);
        int i(0), j(0), n(grid.size());
        vector<int> rMax(n, INT_MIN);
        vector<int> cMax(n, INT_MIN);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                rMax[i] = max(rMax[i], grid[i][j]);
                cMax[j] = max(cMax[j], grid[i][j]);
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                ans += min(rMax[i], cMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

