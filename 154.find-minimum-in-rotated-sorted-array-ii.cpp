/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
private:
    int findMin(vector<int>& nums, int begin, int end)
    {
        if (begin < 0 or end >= nums.size() or begin > end) return -1;
        
        int mid = begin + ((end - begin) >> 1);
        while (mid < end && nums[mid] == nums[end]) --end;
        while (begin < mid && nums[mid] == nums[begin]) ++begin;
        if (begin == end) return nums[end];
        if (nums[mid] > nums[end]) return findMin(nums, mid + 1, end);
        else return findMin(nums, begin, mid);
    }
};

