/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        if (n <= 2) return n;
        int half(n >> 1);
        return (half - lastRemaining(half) + 1) << 1;
    }
};
// @lc code=end

