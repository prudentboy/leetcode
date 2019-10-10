/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i(1); i < dp.size(); ++i)
        {
            for (int n : nums) if (n <= i) dp[i] += dp[i - n];
            //cout << i << ' ' << dp[i] << endl;
        }
        return dp.back();
    }
};
// @lc code=end

