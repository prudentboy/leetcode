/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) { return -1; }

        int ans(1);
        int tmp(1);
        while (ans <= K) {
            if (tmp % K == 0) { return ans; }
            tmp = (tmp * 10 + 1) % K;
            ++ans;
        }
        
        return -1;
    }
};
// @lc code=end

