/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 */

// @lc code=start
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        const int stateCnt(1 << n), kInf(n + 1);

        vector<int> dep(n);
        for (auto& depend : dependencies) { dep[depend[1] - 1] |= (1 << (depend[0] - 1)); }

        vector<int> dp(stateCnt, kInf);
        dp[0] = 0;
        for (int state(0); state < stateCnt; ++state) {
            if (dp[state] >= kInf) { continue; }
            int courses(0); // bit map
            for (int i(0); i < n; ++i) {
                if ((state & (1 << i)) > 0) { continue; } // taken already
                if ((dep[i] & state) != dep[i]) { continue; } // untakable
                courses |= (1 << i);
            }
            int plan(courses);
            while (plan > 0) {
                if (__builtin_popcount(plan) <= k) { dp[state | plan] = min(dp[state | plan], dp[state] + 1); }
                plan = (plan - 1) & courses;
            }
        }
        return dp.back();
    }
};
// @lc code=end

