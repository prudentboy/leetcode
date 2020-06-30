/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (isEven(p) && isEven(q)) {
            p >>= 1;
            q >>= 1;
        }
        if (isEven(p)) { return 2; }
        if (isEven(q)) { return 0; }
        return 1;
    }
private:
    inline bool isEven(int n) {
        return (n & 1) == 0;
    }
};
// @lc code=end

