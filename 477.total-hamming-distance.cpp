/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans(0);

        int ones(0), zeros(0), bit(0);
        for (int i(0); i < 32; ++i)
        {
            ones = zeros = 0;
            bit = (1 << i);
            for (int n : nums)
            {
                if (bit & n) ++ones;
                else ++zeros;
            }
            ans += ones * zeros;
        }

        return ans;
    }
};
// @lc code=end

