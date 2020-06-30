/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
if (nums.size() < k) return {};

        vector<double> ans(nums.size() - k + 1, 0.0);
        multiset<int> small, big;
        int index(0);
        for (int i(0); i < nums.size(); ++i)
        {
            if (i >= k)
            {
                if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
                else big.erase(big.find(nums[i - k]));
            }
            if (small.size() <= big.size())
            {
                if (big.empty() || nums[i] <= *big.begin()) small.insert(nums[i]);
                else
                {
                    small.insert(*big.begin());
                    big.erase(big.begin());
                    big.insert(nums[i]);
                }
            }
            else
            {
                if (nums[i] >= *small.rbegin()) big.insert(nums[i]);
                else
                {
                    big.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            index = i + 1 - k;
            if (index >= 0)
            {
                if ((k & 1) == 1) ans[index] = *(small.rbegin());
                else ans[index] = ((double)(*(small.rbegin())) + *(big.begin())) / 2.0;
            }
        }
        return ans;
    }
};
// @lc code=end

