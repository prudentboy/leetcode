/*
 * @lc app=leetcode id=1276 lang=cpp
 *
 * [1276] Number of Burgers with No Waste of Ingredients
 */

// @lc code=start
class Solution {
public:
    vector<int> numOfBurgers(int A, int B) {
        if ((A & 1) == 1) { return {}; }
        if (A < (B << 1) || A > (B << 2)) { return {}; }
        return {(A - (B << 1)) >> 1, ((B << 2) - A) >> 1};
    }
};
// @lc code=end

