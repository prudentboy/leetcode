/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());

        int i(nums.size()), j((nums.size() + 1)/ 2);
        for (int k(0); k < nums.size(); ++k)
        {
            if (k % 2 == 0) nums[k] = tmp[--j];
            else nums[k] = tmp[--i]; 
        }

        return;
    }
};

