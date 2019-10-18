/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        int i(0), j(0);
        for (i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
            {
                //cout << i << ' ' << nums[i] << ' ' << nums[i] - 1 << endl;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1) ans.push_back(nums[i]);
        }

        return ans;
    }
};
// @lc code=end

