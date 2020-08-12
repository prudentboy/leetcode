/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m(matrix.size()), n(matrix[0].size());
        vector<vector<int>> prefixSums(m, vector<int>(n + 1));
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                prefixSums[i][j + 1] = prefixSums[i][j] + matrix[i][j];
            }
        }

        int ans(0), cur(0);
        unordered_map<int, int> ump;
        for (int i(0); i < n; ++i) {
            for (int j(i); j < n; ++j) {
                cur = 0;
                ump.clear();
                ++ump[cur];
                for (int k(0); k < m; ++k) {
                    cur += prefixSums[k][j + 1] - prefixSums[k][i];
                    if (ump.count(cur - target) > 0) { ans += ump[cur - target]; }
                    ++ump[cur];
                }
            }
        }

        return ans;
    }
};
// @lc code=end

