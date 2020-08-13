/*
 * @lc app=leetcode id=1478 lang=cpp
 *
 * [1478] Allocate Mailboxes
 */

// @lc code=start
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        const int n(houses.size()), kInf(1e7);
        sort(houses.begin(), houses.end());

        vector<vector<int>> costs(n, vector<int>(n, -1));
        auto cost = [&](int i, int j) {
            if (i == j) { return 0; }
            if (i > j) { swap(i, j); }
            if (costs[i][j] >= 0) { return costs[i][j]; }
            int mid(i + ((j - i) >> 1)), len(j - i + 1);
            int ret(0), pos(houses[mid]);
            if ((len & 1) == 0) { ++pos; }
            for (int l(i); l <= j; ++l) { ret += abs(houses[l] - pos); }
            return costs[i][j] = ret;
        };

        vector<vector<int>> memo(k + 1, vector<int>(n, kInf));
        function<int(int, int)> dp = [&](int cnt, int idx) {
            if (cnt > idx) { return 0; }
            if (cnt == 1) { return cost(0, idx); }
            if (memo[cnt][idx] != kInf) { return memo[cnt][idx]; }
            int ret(kInf);
            for (int i(0); i < idx; ++i) {
                ret = min(ret, dp(cnt - 1, i) + cost(i + 1, idx));
            }
            return memo[cnt][idx] = ret;
        };

        return dp(k, n - 1);
    }
};
// @lc code=end

