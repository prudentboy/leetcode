/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans(0);
        int tmp(0);
        for (int n : nums) {
            tmp = 0;
            while (n > 0) {
                ++tmp;
                n /= 10;
            }
            if ((tmp & 1) == 0) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

