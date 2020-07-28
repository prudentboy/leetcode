/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 */

// @lc code=start
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int ans(1), n(A.size());

        vector<vector<int>> dp(n, vector<int>(2));
        dp[n - 1][0] = dp[n - 1][1] = 1;
        map<int, int> m;
        m[A.back()] = n - 1;

        for (int i(n - 2); i >= 0; --i) {
            auto odd(m.lower_bound(A[i]));
            if (odd != m.end()) { dp[i][1] = dp[odd->second][0]; }
            auto even(m.upper_bound(A[i]));
            if (even != m.begin()) { dp[i][0] = dp[prev(even)->second][1]; }
            if (dp[i][1] == 1) { ++ans; }
            m[A[i]] = i;
        }

        return ans;
    }
};
// @lc code=end

