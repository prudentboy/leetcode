/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int mnow(nums[0]);
        int i(0), j(0);
        for (i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < mnow)
            {
                mnow = nums[i];
                continue;
            }
            for (j = nums.size() - 1; j > i; --j)
                if (nums[j] > mnow && nums[j] < nums[i]) return true;
        }
        
        return false;
    }
};
// @lc code=end

