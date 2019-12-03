/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int mn(INT_MAX), mx(INT_MIN);
        for (int n : nums)
        {
            mn = min(mn, n);
            mx = max(mx, n);
        }
        vector<int> v(mx - mn + 1, 0);
        for (int n : nums) v[n - mn] += n;
        return earnMax(v);
    }
private:
    int earnMax(const vector<int>& v)
    {
        int dp(0), dp1(0), dp2(0);
        for (int i(0); i < v.size(); ++i)
        {
            dp = max(dp1 + v[i], dp2);
            dp1 = dp2;
            dp2 = dp;
        }
        return dp;
    }
};
// @lc code=end

