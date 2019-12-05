/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum1(accumulate(s1.begin(), s1.end(), 0));
        int sum2(accumulate(s2.begin(), s2.end(), 0));
        int i(0), j(0);
        int m(s1.size()), n(s2.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (i = 1; i <= m; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return sum1 + sum2 - (dp[m][n] << 1);
    }
};
// @lc code=end

