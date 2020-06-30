/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */

// @lc code=start
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis(abs(target[0]) + abs(target[1]));
        for (const vector<int>& p : ghosts) {
            if (culDis(p, target) <= dis) return false;
        }
        return true;
    }
private:
    int culDis(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
// @lc code=end

