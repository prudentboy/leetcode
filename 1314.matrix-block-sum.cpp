/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m(mat.size()), n(mat[0].size());

        int i(0), j(0);
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (i = 1; i < m + 1; ++i) {
            for (j = 1; j < n + 1; ++j) {
                sums[i][j] = mat[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                ans[i][j] = calBlockSum(i - K, j - K, i + K, j + K, sums);
            }
        }

        return ans;
    }
private:
    int calBlockSum(int x1, int y1, int x2, int y2, const vector<vector<int>>& sums) {
        x1 = max(0, x1);
        y1 = max(0, y1);
        x2 = min(x2, (int)sums.size() - 2);
        y2 = min(y2, (int)sums[0].size() - 2);
        return sums[x2 + 1][y2 + 1] - sums[x2 + 1][y1] - sums[x1][y2 + 1] + sums[x1][y1];
    }
};
// @lc code=end

