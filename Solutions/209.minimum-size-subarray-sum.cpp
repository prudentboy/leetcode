/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;

        int begin(0), end(0), ans(nums.size() + 1), tmp(0);

        while (begin <= end && end < nums.size())
        {
            while (tmp < s && end < nums.size()) tmp += nums[end++];
            while (tmp >= s)
            {
                if (end - begin < ans) ans = end - begin;
                tmp -= nums[begin++];
            }
        }

        return ans > nums.size() ? 0 : ans;
    }
};

