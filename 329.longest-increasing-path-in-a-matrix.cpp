/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans(0);
        if (matrix.empty() || matrix[0].empty()) return ans;
        
        int i(0), j(0), m(matrix.size()), n(matrix[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (i = 0; i < matrix.size(); ++i)
        {
            for (j = 0; j < matrix[0].size(); ++j)
            {
                update(matrix, dp, i, j, ans);
            }
        }
        
        return ans;
    }
private:
    int update(const vector<vector<int>>& m, vector<vector<int>>& dp, int i, int j, int& ans)
    {
        if (dp[i][j] > 0) return dp[i][j];
        
        int p(m.size()), q(m[0].size());
        if (i > 0 && m[i - 1][j] < m[i][j]) dp[i][j] = max(dp[i][j], 1 + update(m, dp, i - 1, j, ans));
        if (i + 1 < p && m[i + 1][j] < m[i][j]) dp[i][j] = max(dp[i][j], 1 + update(m, dp, i + 1, j, ans));
        if (j > 0 && m[i][j - 1] < m[i][j]) dp[i][j] = max(dp[i][j], 1 + update(m, dp, i, j - 1, ans));
        if (j + 1 < q && m[i][j + 1] < m[i][j]) dp[i][j] = max(dp[i][j], 1 + update(m, dp, i, j + 1, ans));
        if (dp[i][j] == 0) dp[i][j] = 1;
        
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
};
// @lc code=end

