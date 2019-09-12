/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans(0);
        if (nums.size() < 2) return ans;

        int min(nums[0]), max(nums[0]);

        for (int i(1); i < nums.size(); ++i)
        {
            if (nums[i] > max) max = nums[i];
            if (nums[i] < min) min = nums[i];
        }
        if (max == min) return 0;

        int size = (max - min) / nums.size() + 1, cnt = (max - min) / size + 1;
        vector<int> max_gap(cnt, INT_MIN), min_gap(cnt, INT_MAX);

        int index(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            index = (nums[i] - min) / size;
            if (nums[i] > max_gap[index]) max_gap[index] = nums[i];
            if (nums[i] < min_gap[index]) min_gap[index] = nums[i];
        }

        int pre = 0;
        for (int i = 0; i < cnt; ++i)
        {
            if (max_gap[i] == INT_MIN and min_gap[i] == INT_MAX) continue;
            if (min_gap[i] - max_gap[pre] > ans) ans = min_gap[i] - max_gap[pre];
            pre = i;
        }

        return ans;
    }
};

