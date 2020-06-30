/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        
        vector<int> ans(2, 0);
        int two(0);
        for (int n : nums) two ^= n;
        two &= -two;
        for (int n : nums)
        {
            if ((n & two) != 0) ans[0] ^= n;
            else ans[1] ^= n;
        }

        return ans;
    }
};

