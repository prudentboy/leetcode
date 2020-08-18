/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */

// @lc code=start
class Solution {
public:
    int palindromePartition(string s, int k) {
        const int n(s.size());

        vector<vector<int>> costs(n, vector<int>(n));
        for (int i(1); i < n; ++i) { if (s[i] != s[i - 1]) { costs[i - 1][i] = 1; } }
        for (int len(3); len <= n; ++len) {
            for (int i(0); i + len <= n; ++i) {
                int j(i + len - 1);
                costs[i][j] = costs[i + 1][j - 1];
                if (s[i] != s[j]) { ++costs[i][j]; }
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, n + 1));
        for (int i(0); i < n; ++i) {
            dp[i][1] = costs[0][i];
            for (int d(2); d <= k; ++d) {
                for (int j(0); j < i; ++j) {
                    dp[i][d] = min(dp[i][d], dp[j][d - 1] + costs[j + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
// @lc code=end

