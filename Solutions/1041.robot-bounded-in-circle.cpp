/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        const vector<vector<int>> direct({{0, 1}, {-1, 0}, {0, -1}, {1, 0}});

        int dir(0);
        int dx(0), dy(0);

        for (char c : instructions) {
            switch (c) {
                case 'G' :
                    dx += direct[dir][0];
                    dy += direct[dir][1];
                    break;
                case 'L' :
                    dir = (dir + 1) % 4;
                    break;
                case 'R' :
                    dir = (dir + 3) % 4;
                    break;
            }
        }
        if (dx == 0 && dy == 0) { return true; }
        if (dir > 0) { return true; }
        
        return false;
    }
};
// @lc code=end

