/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans(0);
        for (int i = 1; i < points.size(); ++i) {
            ans += timeCnt(points[i - 1], points[i]);
        }
        return ans;
    }
private:
    inline int timeCnt(const vector<int>& p1, const vector<int>& p2) {
        return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1])); 
    }
};
// @lc code=end

