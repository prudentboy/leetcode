/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S < 0) S = -S;
        int sum(accumulate(nums.begin(), nums.end(), 0));
        //if (sum == S) return 1;
        if (sum < S || (sum - S) % 2 == 1) return 0;
        return findSubsetTargetWays(nums, (sum - S) >> 1);
    }
private:
    int findSubsetTargetWays(vector<int>& nums, int target)
    {
        if (nums.empty()) return 0;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int n : nums)
        {
            for (int j(target); j - n >= 0; --j) dp[j] += dp[j - n];
        }

        return dp[target];
    }
};

