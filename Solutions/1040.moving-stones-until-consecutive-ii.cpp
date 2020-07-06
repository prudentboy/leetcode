/*
 * @lc app=leetcode id=1040 lang=cpp
 *
 * [1040] Moving Stones Until Consecutive II
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n(stones.size());
        int mx(stones.back() - stones.front() - n + 1);
        mx -= min(stones[n - 1] - stones[n - 2], stones[1] - stones[0]) - 1;
        int mn(mx);
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            while (stones[i] - stones[j] >= n) { ++j; }
            mn = min(mn, n - i + j - 1);
        }
        if (mn == 1 && mn < mx && (stones.back() - stones[1] == n - 2 || stones[n - 2] - stones.front() == n - 2)) { ++mn; }
        return {mn, mx};
    }
};
// @lc code=end

