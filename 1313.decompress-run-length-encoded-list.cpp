/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int cnt(0);
        for (int i(0); i < nums.size(); i += 2) {
            cnt = nums[i];
            while (cnt-- > 0) {
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end

