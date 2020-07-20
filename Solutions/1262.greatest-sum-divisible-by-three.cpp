/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum(accumulate(nums.begin(), nums.end(), 0));
        if (sum % 3 == 0) { return sum; }
        int mn(INT_MAX), mn1(INT_MAX), mn2(INT_MAX);
        for (int n : nums) {
            if (n % 3 == sum % 3) { mn = min(mn, n);}
            if (n % 3 + sum % 3 == 3) {
                if (n < mn1) {
                    mn2 = mn1;
                    mn1 = n;
                } else if (n < mn2) {
                    mn2 = n;
                }
            }
        }
        //cout << sum << ' ' << mn << ' ' << mn1 << ' ' << mn2 << endl;
        if (mn1 != INT_MAX && mn2 != INT_MAX) { mn = min(mn, mn1 + mn2); }
        if (mn == INT_MAX) { return 0; }
        return sum - mn;
    }
};
// @lc code=end

