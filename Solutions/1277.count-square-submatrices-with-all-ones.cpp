/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m(matrix.size()), n(matrix[0].size());

        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                prefixSum[i + 1][j + 1] = matrix[i][j] + prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j];
            }
        }

        auto rangeSum = [&](int x1, int y1, int x2, int y2) {
            return prefixSum[x2 + 1][y2 + 1] + prefixSum[x1][y1] - prefixSum[x1][y2 + 1] - prefixSum[x2 + 1][y1];
        };

        int ans(0), k(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 1; k <= min(m - i, n - j); ++k) {
                    if (rangeSum(i, j, i + k - 1, j + k - 1) == k * k) { ++ans; }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

