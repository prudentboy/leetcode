/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans(0);

        int i(0), j(0), x(0), y(0);
        for (x = 0; x < board.size(); ++x)
        {
            for (y = 0; y < board[0].size(); ++y)
            {
                if (board[x][y] == 'R')
                {
                    i = x;
                    j = y;
                    break;
                }
            }
        }
        
        //cout << i << ' ' << j << endl;
        
        int tmp(0);
        for (tmp = 1; i - tmp >= 0; ++tmp)
        {
            if (board[i - tmp][j] == 'B') break;
            if (board[i - tmp][j] == 'p')
            {
                ++ans;
                break;
            }
        }
        for (tmp = 1; i + tmp < board.size(); ++tmp)
        {
            if (board[i + tmp][j] == 'B') break;
            if (board[i + tmp][j] == 'p')
            {
                ++ans;
                break;
            }
        }
        for (tmp = 1; j - tmp >= 0; ++tmp)
        {
            if (board[i][j - tmp] == 'B') break;
            if (board[i][j - tmp] == 'p')
            {
                ++ans;
                break;
            }
        }
        for (tmp = 1; j + tmp < board[0].size(); ++tmp)
        {
            if (board[i][j + tmp] == 'B') break;
            if (board[i][j + tmp] == 'p')
            {
                ++ans;
                break;
            }
        }
        return ans;
    }
};

