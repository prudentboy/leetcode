/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
class Solution {
public:
    int findMinStep(string& board, string& hand) {
        //cout << board << '&' << hand << endl;
        int ans(hand.size() + 1);
        if (board.empty()) return ans;
        
        int i(0), j(0), cnt(0);
        string newBoard, newHand;
        unordered_set<char> s;
        for (i = 0; i < hand.size(); ++i)
        {
            if (s.count(hand[i])) continue;
            s.insert(hand[i]);
            for (j = 0; j < board.size(); ++j)
            {
                if (board[j] != hand[i]) continue;
                newBoard.assign(board);
                newHand.assign(hand);
                newBoard.insert(j, 1, hand[i]);
                //cout << newBoard << ' ';
                updateBoard(newBoard);
                //cout << newBoard << endl;
                if (newBoard.empty()) return 1;
                newHand.erase(i, 1);
                cnt = findMinStep(newBoard, newHand);
                if (cnt != -1) ans = min(ans, cnt + 1);
            }
        }
        return ans > hand.size() ? -1 : ans;
    }
private:
    void updateBoard(string& board)
    {
        int i(0), j(0), k(0);
        while (i < board.size())
        {
            for (j = i + 1; j < board.size(); ++j) if (board[j] != board[i]) break;
            if (j - i < 3)
            {
                while (i < j) board[k++] = board[i++];
            }
            else i = j;
        }
        board.resize(k);
        if (k != i) updateBoard(board);
    }
};
// @lc code=end

