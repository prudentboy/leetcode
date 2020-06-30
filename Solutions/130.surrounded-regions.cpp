/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() or board[0].empty()) return;

        int m(board.size()), n(board[0].size());
        vector<vector<bool>> table(m, vector<bool>(n, false));

        for (int j(0); j < n; ++j)
        {
            if ((not table[0][j]) and board[0][j] == 'O') helper(board, 0, j, table);
            if ((not table[m - 1][j]) and board[m - 1][j] == 'O') helper(board, m - 1, j, table);
        }
        for (int i(1); i < m - 1; ++i)
        {
            if ((not table[i][0]) and board[i][0] == 'O') helper(board, i, 0, table);
            if ((not table[i][n - 1]) and board[i][n - 1] == 'O') helper(board, i, n - 1, table);
        }

        for (int i(0); i < m; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'p') board[i][j] = 'O';
            }
        }
    }
private:
    void helper(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& table)
    {
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or table[i][j] or board[i][j] != 'O') return;

        board[i][j] = 'p';
        table[i][j] = true;

        helper(board, i - 1, j, table);
        helper(board, i + 1, j, table);
        helper(board, i, j - 1, table);
        helper(board, i, j + 1, table);
    }
};

