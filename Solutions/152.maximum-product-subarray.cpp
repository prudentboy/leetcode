/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int ans(0);
        int i(0), j(1);
        while (j < nums.size())
        {
            while (i < nums.size() && nums[i] == 0) ++i;
            j = i;
            while (j < nums.size() && nums[j] != 0) ++j;
            ans = max(ans, maxProductWithoutZero(nums, i, --j));
            i = ++j;
        }

        return ans;
    }
private:
    int maxProductWithoutZero(const vector<int>& nums, int begin, int end)
    {
        if (begin < 0 or end >= nums.size() or begin > end) return 0;

        if (begin == end) return max(0, nums[begin]);

        int i(begin), j(begin + 1);

        int tmp(nums[begin]), ans(0);
        if (tmp > ans) ans = tmp;
        while (j <= end)
        {
            tmp *= nums[j++];
            if (tmp > ans) ans = tmp;
        }
        while (i < j)
        {
            tmp /= nums[i++];
            if (tmp > ans) ans = tmp;
        }
        return ans;
    }
};

