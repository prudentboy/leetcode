/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n, 0), col(m, 0);
        for (auto& p : indices) {
            ++row[p[0]];
            ++col[p[1]];
        }

        int ans(0);
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if ((row[i] + col[j]) % 2 == 1) { ++ans; }
            }
        }
        return ans;
    }
};
// @lc code=end

