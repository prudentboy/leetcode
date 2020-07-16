/*
 * @lc app=leetcode id=1144 lang=cpp
 *
 * [1144] Decrease Elements To Make Array Zigzag
 */

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int headBig(0), headSmall(0);
        int left(0), right(0);
        for (int i(0); i < nums.size(); ++i) {
            left = (i == 0 ? INT_MAX : nums[i - 1]);
            right = (i == nums.size() - 1 ? INT_MAX : nums[i + 1]);
            if ((i & 1) == 0) {
                headBig += max(0, -min(left, right) + 1 + nums[i]);
            } else {
                headSmall += max(0, -min(left, right) + 1 + nums[i]);
            }
        }
        return min(headBig, headSmall);
    }
};
// @lc code=end

