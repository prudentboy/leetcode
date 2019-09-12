/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans(0);
        int tmp(0);
        for (int i(0); i < 32; ++i)
        {
            tmp = 0;
            for (int num : nums)
            {
                tmp += ((num >> i) & 1);
                tmp %= 3;
            }
            //cout << i << ' ' << tmp << endl;
            ans |= (tmp << i);
        }
        return ans;
    }
};

