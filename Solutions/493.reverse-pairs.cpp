/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        return helper(nums, 0, nums.size() - 1);
    }
private:
    int helper(vector<int>& nums, int l, int r)
    {
        if (l >= r) return 0;
        int m = l + ((r - l) >> 1);
        int ans = helper(nums, l, m) + helper(nums, m + 1, r);
        int i(0), j(m + 1);
        for (i = l; i <= m; ++i)
        {
            while (j <= r && (long long)nums[j] * 2 < nums[i]) ++j;
            ans += j - m - 1;
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
        return ans;
    }
};
// @lc code=end

