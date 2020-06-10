/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m(key.size()), n(ring.size());
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));

        int diff(0), delta(0);
        int i(0), j(0), k(0);
        for (i = m - 1; i >= 0; --i) {
            for (j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        diff = abs(j - k);
                        delta = min(diff, n - diff);
                        dp[i][j] = min(dp[i][j], delta + dp[i + 1][k]);
                    }
                }
            }
        }

        /*
        for (i = 0; i <= m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        */

        return dp[0][0] + m;
    }
};
// @lc code=end

