/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        int ori(num), now(0), pos(1);
        while (num > 0) {
            if (num % 10 == 6) {
                now = pos + (pos << 1);
            }
            pos *= 10;
            num /= 10;
        }
        return ori + now;
    }
};
// @lc code=end

