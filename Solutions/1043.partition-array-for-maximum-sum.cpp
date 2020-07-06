/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n(A.size());
        vector<int> dp(n + 1);

        int i(0), j(0), mn(0);
        for (i = 1; i <= n; ++i) {
            mn = INT_MIN;
            for (j = 1; j <= K && i - j >= 0; ++j) {
                mn = max(mn, A[i - j]);
                dp[i] = max(dp[i], dp[i - j] + mn * j);
            }
        }

        return dp[n];
    }
};
// @lc code=end

