/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans(0);

        unordered_set<long long int> s_nums(nums.begin(), nums.end());
        long long int left, right;
        for (long long int num : nums)
        {
            left = num - 1;
            right = num + 1;
            s_nums.erase(num);
            while (s_nums.count(left) != 0)
            {
                s_nums.erase(left);
                --left;
            }
            while (s_nums.count(right) != 0)
            {
                s_nums.erase(right);
                ++right;
            }
            if (right - left - 1 > ans) ans = right - left - 1;
        }

        return ans;
    }
};

