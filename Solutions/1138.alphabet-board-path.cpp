/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        int xNow(0), yNow(0), xNext(0), yNext(0);
        string ans;
        char mov(' ');
        int len(0);
        for (const char c : target) {
            getPos(c, xNext, yNext);
            
            if (c != 'z') {
            len = xNext - xNow;
            mov = len > 0 ? 'D' : 'U';
            len = abs(len);
            while (len-- > 0) { ans += mov;}

            len = yNext - yNow;
            mov = len > 0 ? 'R' : 'L';
            len = abs(len);
            while (len-- > 0) { ans += mov;}
            } else {
            len = yNext - yNow;
            mov = len > 0 ? 'R' : 'L';
            len = abs(len);
            while (len-- > 0) { ans += mov;}
                
            len = xNext - xNow;
            mov = len > 0 ? 'D' : 'U';
            len = abs(len);
            while (len-- > 0) { ans += mov;}
            }

            ans += '!';
            xNow = xNext;
            yNow = yNext;
        }
        return ans;
    }
private:
    inline void getPos(const char c, int& x, int& y) {
        int num(c - 'a');
        y = num % 5;
        x = num / 5;
    }
};
// @lc code=end

