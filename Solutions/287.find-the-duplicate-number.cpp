/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow(0), fast(0), head(0);
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        do
        {
            slow = nums[slow];
            head = nums[head];
        } while (head != slow);
        return slow;
    }
};

