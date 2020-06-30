/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty() || points[0].empty()) return 0;

        sort(points.begin(), points.end());
        int ans(1), right(points[0][1]);
        for (int i(1); i < points.size(); ++i)
        {
            if (points[i][0] > right)
            {
                ++ans;
                right = points[i][1];
            }
            else right = min(right, points[i][1]);
        }

        return ans;
    }
};
// @lc code=end

