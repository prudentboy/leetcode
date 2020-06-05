/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m(matrix.size()), n(matrix[0].size());
        int i(0), j(0), k(0), mn_idx(0), mx_val(0);

        vector<int> max_col(n, 0);
        for (i = 0; i < m; ++i) {
            mn_idx = 0;
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] < matrix[i][mn_idx]) { mn_idx = j; }
            }
            if (max_col[mn_idx] != 0) {
                if (max_col[mn_idx] == matrix[i][mn_idx]) { ans.push_back(matrix[i][mn_idx]); }
            } else {
                mx_val = matrix[i][mn_idx];
                for (k = 0; k < m; ++k) {
                    if (matrix[k][mn_idx] > mx_val) {
                        mx_val = matrix[k][mn_idx];
                    }
                }
                max_col[mn_idx] = mx_val;
                if (mx_val == matrix[i][mn_idx]) { ans.push_back(mx_val); }
            }
        }
        return ans;
    }
};
// @lc code=end

