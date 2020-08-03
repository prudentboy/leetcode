/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1(str1.size()), n2(str2.size());
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        int i(0), j(0);
        for (i = 1; i <= n1; ++i) {
            for (j = 1; j <= n2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        string ans(n1 + n2 - dp[n1][n2], ' ');
        int idx(ans.size());
        while (n1 > 0 || n2 > 0) {
            if (n1 > 0 && n2 > 0) {
                if (str1[n1 - 1] == str2[n2 - 1]) {
                    ans[--idx] = str1[n1 - 1];
                    --n1;
                    --n2;
                } else if (dp[n1][n2] == dp[n1 - 1][n2]) {
                    ans[--idx] = str1[--n1];
                } else {
                    ans[--idx] = str2[--n2];
                }
            } else if (n1 > 0) {
                ans[--idx] = str1[--n1];
            } else {
                ans[--idx] = str2[--n2];
            }
        }
        return ans;
    }
};
// @lc code=end

