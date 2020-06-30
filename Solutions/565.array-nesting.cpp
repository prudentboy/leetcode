/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int n(nums.size());
        int ans(0), len(0);
        vector<bool> flag(n, false);
        for (int i(0); i < n; ++i)
        {
            if (flag[i]) continue;
            len = cntLoop(nums, flag, i);
            ans = max(ans, len);
        }
        return ans;
    }
private:
    inline int cntLoop(const vector<int>& nums, vector<bool>& flag, int i)
    {
        if (nums[i] == i) return 1;

        int start(i), ans(1);
        while (nums[i] != start)
        {
            ++ans;
            flag[i] = true;
            i = nums[i];
        }
        return ans;
    }
};
// @lc code=end

