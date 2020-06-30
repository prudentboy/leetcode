/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        for (int i(0); i < senate.size(); ++i)
        {
            if (senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }
        while (!qr.empty() && !qd.empty())
        {
            if (qr.front() < qd.front()) qr.push(qr.front() + senate.size());
            else qd.push(qd.front() + senate.size());
            qr.pop();
            qd.pop();
        }
        return qr.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end

