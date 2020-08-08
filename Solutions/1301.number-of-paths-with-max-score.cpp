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
        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n, {-1, -1}));
        dp[m - 1][n - 1] = {0, 1};
        for (int i(m - 1); i >= 0; --i) {
            for (int j(n - 1); j >= 0; --j) {
                if ((i == m - 1 && j == n - 1) || board[i][j] == 'X') { continue; }
                long cnt(0), mx(0), cur(board[i][j] == 'E' ? 0 : board[i][j] - '0');
                auto update = [&](int x, int y) {
                    if (x >= m || y >= n || board[x][y] == 'X') { return; }
                    if (dp[x][y].first > mx) {
                        mx = dp[x][y].first;
                        cnt = dp[x][y].second;
                    } else if (dp[x][y].first == mx) {
                        cnt += dp[x][y].second;
                    }
                };
                update(i + 1, j);
                update(i, j + 1);
                update(i + 1, j + 1);
                dp[i][j] = {cnt <= 0 ? 0 : cur + mx, cnt % 1000000007};
                //cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << endl;
            }
        }
        if (dp[0][0].second < 0 || dp[0][0].first < 0) { return {0,0}; }
        return {(int)dp[0][0].first, (int)dp[0][0].second};
    }
};
// @lc code=end

