/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        const int M(1e9 + 7);
        long ans(1);
        for (int i(1); i <= n; ++i) {
            ans *= i;
            ans %= M;
            ans *= (2 * i - 1) % M;
            ans %= M;
        }
        return ans;
    }
};
// @lc code=end

