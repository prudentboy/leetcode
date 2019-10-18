/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int ans(0);
        nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
        int mid(nums[nums.size() >> 1]);
        for (int n : nums) ans += abs(n - mid);
        return ans;
    }
};
// @lc code=end

