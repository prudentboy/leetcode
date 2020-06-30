/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0-dead, 1-live, 2-to_die, -1-to_reproduce
        if (board.empty() || board[0].empty()) return;
        int x(board.size()), y(board[0].size());
        int cnt(0);
        for (int i(0); i < x; ++i)
        {
            for (int j(0); j < y; ++j)
            {
                cnt = neighborCnt(board, i, j);
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (board[i][j] == 0 && cnt == 3) board[i][j] = -1;
            }
        }
        for (int i(0); i < x; ++i)
        {
            for (int j(0); j < y; ++j)
            {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
private:
    int neighborCnt(const vector<vector<int>>& board, int i, int j) {
        int cnt(0);
        int x(board.size()), y(board[0].size());
        if (i > 0 && j > 0 && board[i - 1][j - 1] > 0) ++cnt;
        if (i > 0 && board[i - 1][j] > 0) ++cnt;
        if (i > 0 && j < y - 1 && board[i - 1][j + 1] > 0) ++cnt;
        if (j > 0 && board[i][j - 1] > 0) ++cnt;
        if (j < y - 1 && board[i][j + 1] > 0) ++cnt;
        if (i < x - 1 && j > 0 && board[i + 1][j - 1] > 0) ++cnt;
        if (i < x - 1 && board[i + 1][j] > 0) ++cnt;
        if (i < x - 1 && j < y - 1 && board[i + 1][j + 1] > 0) ++cnt;
        return cnt;
    }
};

