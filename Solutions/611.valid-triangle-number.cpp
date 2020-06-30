/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans(0);
        int i(0), j(0), k(0);
        for (i = 0; i < nums.size() - 2; ++i)
            for (j = i + 1; j < nums.size() - 1; ++j)
                for (k = j + 1; k < nums.size(); ++k)
                    if (nums[i] + nums[j] > nums[k]) ++ans;
        
        return ans;
    }
};
// @lc code=end

