/*
 * @lc app=leetcode id=782 lang=cpp
 *
 * [782] Transform to Chessboard
 */

// @lc code=start
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n(board.size()), rowSum(0), rowCnt(0), colSum(0), colCnt(0);
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (((board[0][0] + board[0][j] + board[i][0] + board[i][j]) & 1) == 1) { return -1; }
            }
        }
        for (i = 0; i < n; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            if (board[0][i] == (i & 1)) { ++colCnt; }
            if (board[i][0] == (i & 1)) { ++rowCnt; }
        }
        if (rowSum != (n + 1) >> 1 && rowSum != n >> 1) { return -1; }
        if (colSum != (n + 1) >> 1 && colSum != n >> 1) { return -1; }
        if ((n & 1) == 1) {
            if ((colCnt & 1) == 1) { colCnt = n - colCnt; }
            if ((rowCnt & 1) == 1) { rowCnt = n - rowCnt; }
        } else {
            colCnt = min(colCnt, n - colCnt);
            rowCnt = min(rowCnt, n - rowCnt);
        }

        return (colCnt + rowCnt) >> 1;
    }
};
// @lc code=end

