/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        unordered_map<int, int> cnt, begin, end;
        int tmp(0), max(0), ans(nums.size() + 1);

        for (int i(0); i < nums.size(); ++i)
        {
            if (cnt.find(nums[i]) == cnt.end())
            {
                begin[nums[i]] = i;
                end[nums[i]] = i;
                cnt[nums[i]] = 1;
            }
            else
            {
                ++cnt[nums[i]];
                end[nums[i]] = i;
            }
            if (cnt[nums[i]] > max) max = cnt[nums[i]];
        }
        for (const auto& p : cnt)
        {
            if (p.second != max) continue;
            tmp = end[p.first] - begin[p.first] + 1;
            if (tmp < ans) ans = tmp;
        }

        return ans;
    }
};

