/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n(books.size());
        vector<vector<int>> dp(n, vector<int>(n));
        int i(0), j(0), k(0);
        for (i = 0; i < n; ++i) { dp[i][i] = books[i][1]; }
        for (int l(2); l <= n; ++l) {
            for (i = 0; i + l <= n; ++i) {
                j = i + l - 1;
                dp[i][j] = INT_MAX;
                k = i;
                int w(0), h(0);
                while (k <= j) {
                    w += books[k][0];
                    if (w > shelf_width) { break; }
                    h = max(h, books[k][1]);
                    dp[i][j] = min(dp[i][j], h + (k == j ? 0 : dp[k + 1][j]));
                    ++k;
                }
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

