/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num - 1) & num) == 0 && num % 3 == 1;
    }
};
// @lc code=end

