/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return 0;

        int ans(0);
        sort(intervals.begin(), intervals.end());
        int left(0), right(intervals[0][1]);
        for (int i(1); i < intervals.size(); ++i)
        {
            left = intervals[i][0];
            if (left < right)
            {
                ++ans;
                right = min(right, intervals[i][1]);
            }
            else right = intervals[i][1];
        }
        return ans;
    }
};
// @lc code=end

