/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> ans(board);
        int i(click[0]), j(click[1]);
        if (board[i][j] == 'M') ans[i][j] = 'X';
        else if (board[i][j] == 'E') updateBoard(board, ans, i, j);
        return ans;
    }
private:
    void updateBoard(const vector<vector<char>>& board, vector<vector<char>>& ans, int i, int j)
    {
        int m(board.size()), n(board[0].size());
        if (i < 0 || i >= m || j < 0 || j >= n || ans[i][j] != 'E') return;

        int cnt = countMines(board, i, j);
        ans[i][j] = (cnt == 0 ? 'B' : '0' + cnt);
        //cout << i << ' ' << j << ' ' << cnt << ' ' << ans[i][j] << endl;
        if (cnt == 0)
        {
            updateBoard(board, ans, i - 1, j - 1);
            updateBoard(board, ans, i - 1, j);
            updateBoard(board, ans, i - 1, j + 1);
            updateBoard(board, ans, i, j - 1);
            updateBoard(board, ans, i, j + 1);
            updateBoard(board, ans, i + 1, j - 1);
            updateBoard(board, ans, i + 1, j);
            updateBoard(board, ans, i + 1, j + 1);
        }
        return;
    }
    int countMines(const vector<vector<char>>& board, int i, int j)
    {
        int ans(0);
        int m(board.size()), n(board[0].size());
        if (i > 0 && j > 0 && board[i - 1][j - 1] == 'M') ++ans;
        if (i > 0 && board[i - 1][j] == 'M') ++ans;
        if (i > 0 && j + 1 < n && board[i - 1][j + 1] == 'M') ++ans;
        if (j > 0 && board[i][j - 1] == 'M') ++ans;
        if (j + 1 < n && board[i][j + 1] == 'M') ++ans;
        if (i + 1 < m && j > 0 && board[i + 1][j - 1] == 'M') ++ans;
        if (i + 1 < m && board[i + 1][j] == 'M') ++ans;
        if (i + 1 < m && j + 1 < n && board[i + 1][j + 1] == 'M') ++ans;
        return ans;
    }
};
// @lc code=end

