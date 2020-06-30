/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row(matrix.size()), col(matrix[0].size());
        int ans(0);
        vector<vector<int>> dp(row, vector<int>(col, 0));

        int i(0), j(0);
        for (; i < row; ++i)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for (; j < col; ++j)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                ans = 1;
            }
        }
        for (i = 1; i < row; ++i)
        {
            for (j = 1; j < col; ++j)
            {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (dp[i][j] > ans) ans = dp[i][j];
            }
        }
        return ans * ans;
    }
};

