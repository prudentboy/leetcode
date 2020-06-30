/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m(word1.size()), n(word2.size());
        int i(0), j(0);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (i = 1; i < m + 1; ++i)
        {
            for (j = 1; j < n + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return m + n - 2 * dp[m][n];
    }
};
// @lc code=end

