/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 */

// @lc code=start
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        const int n(arr.size());
        vector<int> memo(n);

        function<int(int)> dp = [&](int idx) {
            if (memo[idx] > 0) { return memo[idx]; }
            int mn_idx(max(0, idx - d)), mx_idx(min(n - 1, idx + d));
            int ret(1);
            for (int i(idx + 1); i <= mx_idx && arr[idx] > arr[i]; ++i) { ret = max(ret, dp(i) + 1); }
            for (int i(idx - 1); i >= mn_idx && arr[idx] > arr[i]; --i) { ret = max(ret, dp(i) + 1); }
            return memo[idx] = ret;
        };

        int ans(1);
        for (int i(0); i < n; ++i) { ans = max(ans, dp(i)); }
        return ans;
    }
};
// @lc code=end

