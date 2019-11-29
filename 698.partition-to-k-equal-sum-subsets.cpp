/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        int sum(accumulate(nums.begin(), nums.end(), 0));
        if (sum % k != 0) return false;
        
        vector<int> buckets(k, 0);
        sort(nums.rbegin(), nums.rend());
        return canPartitionKSubsets(nums, buckets, sum / k, 0);
    }
private:
    bool canPartitionKSubsets(const vector<int>& nums, vector<int>& buckets, const int target, int idx)
    {
        if (idx >= nums.size())
        {
            for (int n : buckets)
            {
                if (n != target) return false;
            }
            return true;
        }

        int num(nums[idx]);
        for (int i(0); i < buckets.size(); ++i)
        {
            if (buckets[i] + num > target) continue;
            buckets[i] += num;
            if (canPartitionKSubsets(nums, buckets, target, idx + 1)) return true;
            buckets[i] -= num;
        }
        return false;
    }
};
// @lc code=end

