/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        const size_t len(nums.size());
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, len - 1), robRange(nums, 1, len));
    }
private:
    int robRange(const vector<int>& nums, size_t begin, size_t end)
    {
        int p(0), pp(0), now(0);
        pp = nums[begin];
        p = max(nums[begin], nums[begin + 1]);
        for (int i(begin + 2); i < end; ++i)
        {
            now = max(p, pp + nums[i]);
            pp = p;
            p = now;
        }
        return p;
    }
};

