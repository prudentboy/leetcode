/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m(mat.size()), n(mat[0].size());
        vector<vector<int>> ans(m, vector<int>(n));
        int i(0), j(0), k(0), idx(0);
        j = 0;
        for (i = m - 1; i >= 0; --i) {
            vector<int> arr;
            for (k = 0; i + k < m && j + k < n; ++k) { arr.emplace_back(mat[i + k][j + k]); }
            sort(arr.begin(), arr.end());
            idx = 0;
            for (k = 0; i + k < m && j + k < n; ++k) { ans[i + k][j + k] = arr[idx++]; }
        }
        i = 0;
        for (j = 1; j < n; ++j) {
            vector<int> arr;
            for (k = 0; i + k < m && j + k < n; ++k) { arr.emplace_back(mat[i + k][j + k]); }
            sort(arr.begin(), arr.end());
            idx = 0;
            for (k = 0; i + k < m && j + k < n; ++k) { ans[i + k][j + k] = arr[idx++]; }
        }
        return ans;
    }
};
// @lc code=end

