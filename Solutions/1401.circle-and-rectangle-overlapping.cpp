/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx(0);
        if (x_center > x2) { dx = x_center - x2; }
        else if (x_center < x1) { dx = x1 - x_center; }
        int dy(0);
        if (y_center > y2) { dy = y_center - y2; }
        else if (y_center < y1) { dy = y1 - y_center; }
        return dx * dx + dy * dy <= radius * radius;
    }
};
// @lc code=end

