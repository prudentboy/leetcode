/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty() || k <= 1) return 0;

        int i(0), j(0), n(nums.size());
        int ans(0);
        long long int tmp(1);
        for (i = 0; i < n; ++i)
        {
            tmp *= nums[i];
            while (tmp >= k) tmp /= nums[j++];
            ans += i - j + 1;
            //cout << i << ' ' << j << ' ' << tmp << ' ' << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

