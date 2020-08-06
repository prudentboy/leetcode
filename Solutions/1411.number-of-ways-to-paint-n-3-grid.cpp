/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
class Solution {
public:
    int numOfWays(int n) {
        constexpr int M = 1000000007;
        long pre2(6), pre3(6), cur2(6), cur3(6);
        for (int i(2); i <= n; ++i) {
            cur2 = pre2 * 3 + pre3 * 2;
            cur3 = pre2 * 2 + pre3 * 2;
            pre2 = cur2 % M;
            pre3 = cur3 % M;
        }
        return (cur2 + cur3) % M;
    }
};
// @lc code=end

