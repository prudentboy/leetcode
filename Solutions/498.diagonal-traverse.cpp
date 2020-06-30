/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m(matrix.size()), n(matrix[0].size());
        vector<int> ans(m * n, 0);
        int i(0), j(0), k(0), l(0), tmp(0);

        ans[k++] = matrix[i][j];
        while (k < ans.size())
        {
            if (k < ans.size()) ans[k++] = j + 1 < n ? matrix[i][++j] : matrix[++i][j];
            //cout << i << ' ' << j << ' ' << k << ' ' << ans[k - 1] << endl;
            while (i + 1 < m && j > 0) ans[k++] = matrix[++i][--j];
            if (k < ans.size()) ans[k++] = i + 1 < m ? matrix[++i][j] : matrix[i][++j];
            //cout << i << ' ' << j << ' ' << k << ' ' << ans[k - 1] << endl;
            while (j + 1 < n && i > 0) ans[k++] = matrix[--i][++j];
        }

        return ans;
    }
};
// @lc code=end

