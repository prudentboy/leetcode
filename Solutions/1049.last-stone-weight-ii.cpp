/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int ans(INT_MAX);
        int n(stones.size());

        int sum(accumulate(stones.begin(), stones.end(), 0));
        vector<bool> dp((sum >> 1) + 1, false);
        dp[0] = true;
        int i(0), m(dp.size());
        for (int stone : stones) {
            for (i = m - 1; i >= 0; --i) {
                dp[i] = dp[i] || (i - stone >= 0 && i - stone < m && dp[i - stone]);
            }
        }
        for (i = m - 1; i >= 0; --i) {
            if (dp[i]) { return abs(sum - (i << 1)); }
        }

        return ans;
    }
};
// @lc code=end

