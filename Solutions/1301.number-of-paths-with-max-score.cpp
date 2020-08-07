/*
 * @lc app=leetcode id=1301 lang=cpp
 *
 * [1301] Number of Paths with Max Score
 */

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m(board.size()), n(board[0].size());
        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n, {0, 1}));
        for (int i(m - 1); i >= 0; --i) {
            for (int j(n - 1); j >= 0; --j) {
                if (i == m - 1 && j == n - 1) { continue; }
                if (board[i][j] == 'X') {
                    dp[i][j] = {0, -1};
                    continue;
                }
                long cnt(0), mx(0), cur(board[i][j] == 'E' ? 0 : board[i][j] - '0');
                if (i < m - 1) {
                    mx = dp[i + 1][j].first;
                    cnt = dp[i + 1][j].second;
                }
                if (j < n - 1) {
                    if (dp[i][j + 1].first == mx) {
                        cnt += dp[i][j + 1].second;
                    } else if (dp[i][j + 1].first > mx) {
                        mx = dp[i][j + 1].first;
                        cnt = dp[i][j + 1].second;
                    }
                }
                dp[i][j] = {cnt <= 0 ? 0 : cur + mx, cnt % 1000000007};
                //cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << endl;
            }
        }
        if (dp[0][0].second <= 0) { return {0,0}; }
        return {(int)dp[0][0].first, (int)dp[0][0].second};
    }
};
// @lc code=end

