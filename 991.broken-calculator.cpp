/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int X, int Y) {
        //cout << X << ' ' << Y << endl;
        if (X >= Y) { return X - Y; }
        if ((Y & 1) == 1) {
            return 1 + brokenCalc(X, Y + 1);
        } else { return 1 + brokenCalc(X, Y >> 1); }
        return 0;
    }
};
// @lc code=end

