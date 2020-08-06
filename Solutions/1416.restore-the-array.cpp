/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution {
public:
    int numberOfArrays(string s, int k) {
        constexpr int M = 1000000007;
        const int n(s.size());
        vector<int> dp(n + 1);
        dp[0] = 1;
        long num(0), tmp(0), fac(1);
        for (int i(1); i <= n; ++i) {
            fac = 1;
            tmp = 0;
            num = s[i - 1] - '0';
            if (num > k) { return 0; }
            if (num > 0) { tmp = dp[i - 1]; }
            for (int j(i - 1); j > 0 && i - j < 10; --j) {
                fac *= 10;
                num += fac * (s[j - 1] - '0');
                if (s[j - 1] == '0') { continue; }
                if (num > k) { break; }
                if (num > 0 && num <= k) { tmp += dp[j - 1]; }
            }
            dp[i] = tmp % M;
            if (dp[i] <= 0) { return 0; }
        }
        return dp.back();
    }
};
// @lc code=end

