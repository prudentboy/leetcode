/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        int ans(1), n(envelopes.size());
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());

        for (int i(1); i < n; ++i)
        {
            for (int j(0); j < i; ++j)
            {
                if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0]) dp[i] = max(dp[i], dp[j] + 1);
            }
            //cout << i << ' ' << dp[i] << endl;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// @lc code=end

