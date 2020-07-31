/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) {
            if (l[1] == r[1]) { return l[0] < r[0]; }
            return l[1] < r[1];
        });
        int ans(2), a(intervals.front().back()), b(intervals.front().back() - 1);
        for (int i(1); i < intervals.size(); ++i) {
            if (b >= intervals[i][0] && a <= intervals[i][1]) { continue; }
            if (a < intervals[i][0] && b < intervals[i][0]) {
                ans += 2;
                a = intervals[i][1];
                b = intervals[i][1] - 1;
            } else {
                ++ans;
                b = intervals[i][1] == a ? intervals[i][1] - 1 : a;
                a = intervals[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end

