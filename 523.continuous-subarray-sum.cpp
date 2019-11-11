/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        
        int i(0), j(0), n(nums.size());
        vector<int> sums(nums);
        for (i = 1; i < n; ++i)
        {
            sums[i] += sums[i - 1];
            if (sums[i] == 0) return true;
            if (k != 0 && sums[i] % k == 0) return true;
        }
        //if (sums.back() < k) return false;

        for (i = 0; i < n - 2; ++i)
            for (j = i + 2; j < n; ++j)
            {
                if (sums[j] == sums[i]) return true;
                if (k != 0 && (sums[j] - sums[i]) % k == 0) return true;
            }
        
        return false;
    }
};
// @lc code=end

