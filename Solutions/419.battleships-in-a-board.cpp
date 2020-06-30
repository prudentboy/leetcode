/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;

        int ans(0);
        int m(board.size()), n(board[0].size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i(0); i < m; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (visited[i][j] || board[i][j] == '.') continue;
                ++ans;
                visited[i][j] = true;
                int k(0);
                if (i + 1 < m && board[i + 1][j] == 'X')
                {
                    k = i + 1;
                    while (k < m && board[k][j] == 'X') visited[k++][j] = true;
                }
                else if (j + 1 < n && board[i][j + 1] == 'X')
                {
                    k = j + 1;
                    while (k < n && board[i][k] == 'X') visited[i][k++] = true;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

