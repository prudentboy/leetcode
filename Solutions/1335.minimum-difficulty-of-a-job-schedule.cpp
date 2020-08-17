/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n(jobDifficulty.size()), kInf(1e7);
        if (d > n) { return -1; }
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, kInf));
        dp[0][0] = 0;

        int mx(0);
        for (int i(1); i <= n; ++i) {
            for (int j(1); j <= d; ++j) {
                mx = 0;
                for (int k = i - 1; k >= j - 1; --k) {
                    mx = max(mx, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + mx);
                }
            }
        }

        return dp[n][d];
    }
};
// @lc code=end

