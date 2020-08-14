/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        constexpr int M(1000000007);
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
        function<int(int, int, int)> dp = [&](int nn, int mm, int kk) {
            if (kk > nn || kk > mm || kk < 1) { return 0; }
            if (kk == 1 && nn == 1) { return mm; }
            if (memo[nn][mm][kk] > 0) { return memo[nn][mm][kk]; }
            long ret(0);
            for (int i(1); i <= mm; ++i) {
                ret += dp(nn - 1, mm, kk);
                ret += dp(nn - 1, i - 1, kk - 1);
                ret -= dp(nn - 1, i - 1, kk);
                ret = (ret + M) % M;
            }
            return memo[nn][mm][kk] = ret;
        };

        return dp(n, m, k);
    }
};
// @lc code=end

