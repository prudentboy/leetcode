/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n(arr.size());

        vector<vector<int>> mxDp(n, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(n));

        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            mxDp[i][i] = arr[i];
            for (j = i + 1; j < n; ++j) {
                mxDp[i][j] = max(mxDp[i][j - 1], arr[j]);
            }
        }

        int l(0), k(0);
        for (l = 2; l <= n; ++l) {
            for (i = 0; i + l <= n; ++i) {
                j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mxDp[i][k] * mxDp[k + 1][j]);
                }
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

