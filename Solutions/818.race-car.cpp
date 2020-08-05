/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
class Solution {
public:
    int racecar(int target) {
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int tar) {
            //cout << tar << endl;
            if (memo.count(tar) > 0) { return memo[tar]; }
            int mxFor(log2(tar + 1));
            if ((1 << mxFor) == tar + 1) { return memo[tar] = mxFor; }
            int ret(mxFor + 2 + dp((1 << (mxFor + 1)) - 1 - tar));
            for (int i(0); i < mxFor; ++i) {
                ret = min(ret, mxFor + i + 2 + dp(tar - (1 << mxFor) + (1 << i)));
            }
            return memo[tar] = ret;
        };

        return dp(target);
    }
};
// @lc code=end

