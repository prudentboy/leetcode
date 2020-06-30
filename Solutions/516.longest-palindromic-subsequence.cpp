/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() < 2) return s.size();

        int n(s.size());
        int i(0), j(0);

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (i = 0; i < n; ++i) dp[i][i] = 1;
        for (i = n - 1; i >= 0; --i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

