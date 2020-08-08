/*
 * @lc app=leetcode id=1250 lang=cpp
 *
 * [1250] Check If It Is a Good Array
 */

// @lc code=start
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int x(nums.front());
        for (int i(1); i < nums.size(); ++i) {
            x = gcd(x, nums[i]);
            if (x == 1) { return true; }
        }
        return x == 1;
    }
};
// @lc code=end

