/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 */

// @lc code=start
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        constexpr int M(1000000007), hatCnt(40);
        const int n(hats.size());

        vector<vector<int>> people(hatCnt + 1);
        for (int i(0); i < hats.size(); ++i) {
            for (int hat : hats[i]) { people[hat].push_back(i); }
        }

        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int i(1); i <= hatCnt; ++i) {
            for (int state((1 << n) - 1); state >= 0; --state) {
                for (int person : people[i]) {
                    if ((state & (1 << person)) > 0) { continue; }
                    int cur(state | (1 << person));
                    dp[cur] += dp[state];
                    dp[cur] %= M;
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end

