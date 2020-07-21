/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 */

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mAng(6 * minutes), hAng(30 * hour + minutes / 2.0);
        double ans(abs(mAng - hAng));
        if (ans > 180) { ans = 360 - ans; }
        return ans;
    }
};
// @lc code=end

