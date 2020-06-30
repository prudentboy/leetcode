/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        
        vector<int> dp(nums.size(), 1);
        vector<int> helper(nums.size(), -1);
        
        int max(1), end(0);
        vector<int> ans;
        ans.reserve(nums.size());
        sort(nums.begin(), nums.end());

        for (int i(1); i < nums.size(); ++i)
        {
            for (int j(0); j < i; ++j)
            {
                if (nums[i] % nums[j] != 0) continue;
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    helper[i] = j;
                }
                if (dp[i] > max)
                {
                    max = dp[i];
                    end = i;
                }
            }
        }

        if (max < 2) return {nums[0]};

        do
        {
            ans.push_back(nums[end]);
            end = helper[end];
        } while (end != -1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

