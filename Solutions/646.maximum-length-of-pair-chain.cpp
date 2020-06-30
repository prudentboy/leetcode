/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end());

        int ans(1);
        int i(0), j(0), n(pairs.size());
        vector<int> dp(n, 1);
        for (i = 1; i < n; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                if (pairs[j][1] < pairs[i][0] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

