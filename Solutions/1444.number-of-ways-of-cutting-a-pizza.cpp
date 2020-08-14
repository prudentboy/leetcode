/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int M(1000000007);
        const int m(pizza.size()), n(pizza[0].size());
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j];
                if (pizza[i][j] == 'A') { ++prefixSum[i + 1][j + 1]; }
            }
        }

        auto rangeSum = [&](int x1, int y1, int x2, int y2) -> bool {
            return (prefixSum[x2 + 1][y2 + 1] - prefixSum[x2 + 1][y1] - prefixSum[x1][y2 + 1] + prefixSum[x1][y1]) > 0;
        };

        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        function<int(int, int, int)> dp = [&](int row, int col, int cnt) {
            if (cnt == 1) { return rangeSum(row, col, m - 1, n - 1) ? 1 : 0; }
            if (memo[row][col][cnt] != -1) { return memo[row][col][cnt]; }
            long ret(0);
            for (int i(row + 1); i < m; ++i) {
                if (rangeSum(row, col, i - 1, n - 1)) { ret += dp(i, col, cnt - 1); }
            }
            for (int j(col + 1); j < n; ++j) {
                if (rangeSum(row, col, m - 1, j - 1)) { ret += dp(row, j, cnt - 1); }
            }
            ret %= M;
            return memo[row][col][cnt] = ret;
        };

        return dp(0, 0, k);
    }
};
// @lc code=end

