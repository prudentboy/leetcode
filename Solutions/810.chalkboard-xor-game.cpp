/*
 * @lc app=leetcode id=810 lang=cpp
 *
 * [810] Chalkboard XOR Game
 */

// @lc code=start
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n(nums.size());
        if ((n & 1) == 0) { return true; }

        int x(0);
        for (int num : nums) x ^= num;
        return x == 0;
    }
};
// @lc code=end

