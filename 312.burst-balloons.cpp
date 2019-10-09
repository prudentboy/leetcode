/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        int i(0), n(nums.size());
        vector<int> ns(n + 2, 1);
        for (i = 1; i < ns.size() - 1; ++i) ns[i] = nums[i - 1];
        //for (i = 0; i < ns.size(); ++i) cout << ns[i] << ' ';
        //cout << endl;
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        int len(0), j(0), k(0);
        for (len = 1; len <= n; ++len)
        {
            for (i = 1; i <= n - len + 1; ++i)
            {
                j = i + len - 1;
                for (k = i; k <= j; ++k)
                {
                    dp[i][j] = max(dp[i][j], ns[i - 1] * ns[k] * ns[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        
        return dp[1][n];
    }
};
// @lc code=end

