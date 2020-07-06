/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> mst;
        
        int n(nums.size());
        int ans(0);
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            mst.insert(nums[i]);
            while (!mst.empty() && *mst.rbegin() - *mst.begin() > limit) {
                mst.erase(mst.equal_range(nums[j++]).first);
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end

