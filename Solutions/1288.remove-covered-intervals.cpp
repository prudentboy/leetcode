/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        /* bruce with ust
        int n(intervals.size());
        unordered_set<int> rmed;
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j || rmed.count(j) > 0) { continue; }
                if (intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
                    rmed.insert(i);
                    break;
                }
            }
        }
        return n - rmed.size();
        */
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) {
            if (l[0] == r[0]) { return l[1] > r[1]; }
            return l[0] < r[0];
        });

        int n(intervals.size()), rmCnt(0);
        int r(intervals[0][1]);
        for (int i(1); i < n; ++i) {
            if (intervals[i][1] <= r) {
                ++rmCnt;
            } else {
                r = intervals[i][1];
            }
        }
        return n - rmCnt;
    }
};
// @lc code=end

