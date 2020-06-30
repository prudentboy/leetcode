/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, nums);
    }
private:
    int helper(int n, vector<int>& v)
    {
        if (n == 0) return 1;
        int ans(0);
        for (int i = 0; i < n; ++i)
        {
            if (n % v[i] == 0 || v[i] % n == 0)
            {
                swap(v[i], v[n - 1]);
                ans += helper(n - 1, v);
                swap(v[i], v[n - 1]);
            }
        }
        return ans;
    }
};
// @lc code=end

