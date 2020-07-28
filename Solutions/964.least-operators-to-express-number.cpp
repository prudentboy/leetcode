/*
 * @lc app=leetcode id=964 lang=cpp
 *
 * [964] Least Operators to Express Number
 */

// @lc code=start
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        double div(log(x));
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int tar) {
            if (tar == 0) { return 0; }
            if (tar < x) { return min((tar << 1) - 1, (x - tar) << 1); }
            if (memo.count(tar) > 0) { return memo[tar]; }
            int k(log(tar) / div);
            long long int p(pow(x, k));
            if (p == tar) { return memo[tar] = k - 1; }
            int ret(dp(tar - p) + k);
            if (p * x - tar < tar) {
                ret = min(ret, dp(p * x - tar) + k + 1);
            }
            return memo[tar] = ret;
        };

        return dp(target);
    }
};
// @lc code=end

