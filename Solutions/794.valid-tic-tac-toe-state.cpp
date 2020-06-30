/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt(0), oCnt(0);
        bool xWin(false), oWin(false);
        for (string& s : board) {
            if (s == "XXX") {
                xWin = true;
            } else if (s == "OOO") {
                oWin = true;
            }
            for (char c : s) {
                if (c == 'X') {
                    ++xCnt;
                } else if (c == 'O') {
                    ++oCnt;
                }
            }
        }
        if (xCnt < oCnt || xCnt > oCnt + 1) {
            return false;
        }
        if (board[0][0] + board[1][0] + board[2][0] == 'X' * 3 || \
            board[0][1] + board[1][1] + board[2][1] == 'X' * 3 || \
            board[0][2] + board[1][2] + board[2][2] == 'X' * 3 || \
            board[0][0] + board[1][1] + board[2][2] == 'X' * 3 || \
            board[0][2] + board[1][1] + board[2][0] == 'X' * 3) {
                xWin = true;
        }
        if (board[0][0] + board[1][0] + board[2][0] == 'O' * 3 || \
            board[0][1] + board[1][1] + board[2][1] == 'O' * 3 || \
            board[0][2] + board[1][2] + board[2][2] == 'O' * 3 || \
            board[0][0] + board[1][1] + board[2][2] == 'O' * 3 || \
            board[0][2] + board[1][1] + board[2][0] == 'O' * 3) {
                oWin = true;
        }
        if (xWin && oWin) {
            return false;
        }
        if (xWin && xCnt == oCnt) {
            return false;
        }
        if (oWin && xCnt > oCnt) {
            return false;
        }
        return true;
    }
};
// @lc code=end

