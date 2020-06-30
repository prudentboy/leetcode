/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (z == 0) return true;
        return (z % gcd(x, y) == 0);
    }
private:
    int gcd(int x, int y)
    {
        if (x % y == 0) return y;
        return gcd(y, x % y);
    }
};
// @lc code=end

