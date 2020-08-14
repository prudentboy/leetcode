/*
 * @lc app=leetcode id=1449 lang=cpp
 *
 * [1449] Form Largest Integer With Digits That Add up to Target
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> memo(target + 1, "");

        function<string(int)> dp = [&](int tar) -> string {
            if (tar < 0) { return "0"; }
            if (tar == 0) { return ""; }
            if (memo[tar] != "") { return memo[tar]; }
            string& ret = memo[tar];
            ret = "0";
            for (int i(0); i < 9; ++i) {
                if (dp(tar - cost[i]) == "0" || memo[tar - cost[i]].size() + 1 < ret.size()) { continue; }
                string tmp(memo[tar - cost[i]]);
                tmp = to_string(i + 1) + tmp;
                if (tmp.size() > ret.size() || tmp > ret) { swap(tmp, ret); }
            }
            return ret;
        };

        return dp(target);
    }
};
// @lc code=end

