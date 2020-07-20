/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 */

// @lc code=start
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m(mat.size()), n(mat[0].size());
        
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + mat[i][j];
            }
        }

        auto rangeSum = [&](int x1, int y1, int x2, int y2) -> int {
            return prefixSum[x2 + 1][y2 + 1] - prefixSum[x1][y2 + 1] - prefixSum[x2 + 1][y1] + prefixSum[x1][y1];
        };

        int ans(0);
        int left(0), right(0), mid(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                left = ans + 1;
                right = min(m - i, n - j);
                if (left > right || right < 1) { continue; }
                while (left <= right) {
                    mid = left + ((right - left) >> 1);
                    if (rangeSum(i, j, i + mid - 1, j + mid - 1) > threshold) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (left > min(m - i, n - j) + 1) { continue; }
                ans = left - 1;
            }
        }

        return ans;
    }
};
// @lc code=end

