/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1, 1.0);
        double sum(1.0), ans(0.0);
        for (int i(1); i <= N; ++i) {
            dp[i] = sum / W;
            if (i < K) sum += dp[i];
            else ans += dp[i];
            if (i >= W) sum -= dp[i - W];
        } 
        return ans;
    }
};
// @lc code=end

