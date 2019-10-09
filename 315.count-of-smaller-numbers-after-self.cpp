/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n(nums.size());
        if (n == 0) return nums;
        
        vector<int> ans(n, 0);
        vector<int> helper(1, nums.back());
        
        int i(0), j(0);
        vector<int>::iterator it;
        for (i = n - 2; i >= 0; --i)
        {
            it = lower_bound(helper.begin(), helper.end(), nums[i]);
            ans[i] = it - helper.begin();
            helper.insert(it, nums[i]);
        }
        
        return ans;
    }
};
// @lc code=end

