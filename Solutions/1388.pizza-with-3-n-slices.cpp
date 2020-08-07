/*
 * @lc app=leetcode id=1388 lang=cpp
 *
 * [1388] Pizza With 3n Slices
 */

// @lc code=start
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n(slices.size());
        auto helper = [&](int beg, int end) {
            vector<vector<vector<int>>> dp(end - beg + 1, vector<vector<int>>(n / 3 + 1, vector<int>(2)));
            for (int i(1); i <= end - beg; ++i) {
                for (int j(1); j <= n / 3; ++j) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + slices[beg + i - 1]);
                    //cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
                }
            }
            return max(dp[end - beg][n / 3][0], dp[end - beg][n / 3][1]);
        };
        return max(helper(0, n - 1), helper(1, n));
    }
};
// @lc code=end

