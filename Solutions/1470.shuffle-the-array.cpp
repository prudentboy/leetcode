/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n << 1);
        int i(0), j(n), k(0);
        while (i < n) {
            ans[k++] = nums[i++];
            ans[k++] = nums[j++]; 
        }
        return ans;
    }
};
// @lc code=end

