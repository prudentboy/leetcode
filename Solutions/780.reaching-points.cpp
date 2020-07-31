/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) { return false; }
        if (sx == tx) { return (ty - sy) % sx == 0; }
        if (sy == ty) { return (tx - sx) % sy == 0; }
        return reachingPoints(sx, sy, tx % ty, ty % tx);
    }
};
// @lc code=end

