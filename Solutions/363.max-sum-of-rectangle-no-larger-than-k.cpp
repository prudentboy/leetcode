/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row(matrix.size()), col(matrix[0].size());
        //cout << row << ' ' << col << endl;
        vector<vector<int>> sums(row, vector<int>(col, 0));

        int i(0), j(0);
        sums[0][0] = matrix[0][0];
        for (i = 1; i < row; ++i) sums[i][0] = matrix[i][0] + sums[i - 1][0];
        for (j = 1; j < col; ++j) sums[0][j] = matrix[0][j] + sums[0][j - 1];
        //cout << "corner" << endl;

        for (i = 1; i < row; ++i)
        {
            for (j = 1; j < col; ++j)
            {
                sums[i][j] = matrix[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
                //cout << i << ' ' << j << ' ' << sums[i][j] << endl;
            }
        }
        //cout << "sum" << endl;

        int ans(INT_MIN), m(0), n(0), tmp(0);
        for (i = 0; i < row; ++i)
        {
            for (j = 0; j < col; ++j)
            {
                for (m = i; m < row; ++m)
                {
                    for (n = j; n < col; ++n)
                    {
                        tmp = sums[m][n];
                        if (i > 0) tmp -= sums[i - 1][n];
                        if (j > 0) tmp -= sums[m][j - 1];
                        if (i > 0 && j > 0) tmp += sums[i - 1][j - 1]; 
                        //cout << i << ' ' << j << ' ' << m << ' ' << n << ' ' << tmp << endl;
                        if (tmp == k) return k;
                        else if (tmp < k) ans = max(ans, tmp);
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

