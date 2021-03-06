/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Play with Chips
 */

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd(0), even(0);
        for (int n : chips) {
            if ((n & 1) == 0) {
                ++even;
            } else {
                ++odd;
            }
        }
        return min(odd, even);
    }
};
// @lc code=end

