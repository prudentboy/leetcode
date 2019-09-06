/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;

        vector<int> nums(ratings.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        }
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1] and nums[i + 1] + 1 > nums[i]) nums[i] = nums[i + 1] + 1;
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

