/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int i(0), j(0);
        int num0(0), num1(0);
        for (const string& str : strs)
        {
            num0 = num1 = 0;
            for (const char c : str) c == '0' ? ++num0 : ++num1;
            for (i = m; i >= num0; --i)
            {
                for (j = n; j >= num1; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - num0][j - num1]);
                    //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

