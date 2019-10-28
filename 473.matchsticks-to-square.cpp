/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;

        int sum(accumulate(nums.begin(), nums.end(), 0));
        if ((sum & 0b11) != 0) return false;

        sort(nums.begin(), nums.end());
        if (nums.back() > (sum >> 2)) return false;

        vector<int> sums(4, 0);
        return helper(nums, sums, nums.size() - 1, sum >> 2);
    }
private:
    bool helper(const vector<int>& nums, vector<int>& sums, int index, const int target)
    {
        if (index < 0) return meetTar(sums, target);
        else
        {
            for (int i(0); i < 4; ++i)
            {
                if (sums[i] + nums[index] > target) continue;
                sums[i] += nums[index];
                if (helper(nums, sums, index - 1, target)) return true;
                sums[i] -= nums[index];
            }
        }
        return false;
    }
    bool meetTar(const vector<int>& sums, const int target)
    {
        if (sums.size() != 4) return false;
        for (const int n : sums) if (n != target) return false;
        return true;
    }
};
// @lc code=end