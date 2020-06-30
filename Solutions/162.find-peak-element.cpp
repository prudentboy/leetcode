/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        return findPeakElement(nums, 0, nums.size() - 1);   
    }
private:
    int findPeakElement(vector<int>& nums, int i, int j)
    {
        if (i > j) return -1;

        int mid = i + ((j - i) >> 1);
        if (isPeakElement(nums, mid)) return mid;
        if (mid == 0) return findPeakElement(nums, mid + 1, j);
        if (mid == nums.size() - 1) return findPeakElement(nums, i, mid - 1);
        if (nums[mid - 1] < nums[mid] and nums[mid] < nums[mid + 1]) return findPeakElement(nums, mid + 1, j);
        else return findPeakElement(nums, i, mid - 1);
    }
    bool isPeakElement(vector<int>& nums, int i)
    {
        if (i < 0 or i >= nums.size()) return false;
        if (nums.size() == 1) return true;
        if (i == 0) return nums[0] > nums[1];
        if (i == nums.size() - 1) return nums[i - 1] < nums[i];
        return nums[i - 1] < nums[i] and nums[i] > nums[i + 1];
    }
};

