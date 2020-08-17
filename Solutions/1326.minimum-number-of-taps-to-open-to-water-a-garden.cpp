/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i(0); i < ranges.size(); ++i) {
            if (ranges[i] == 0) { continue; }
            intervals.emplace_back(make_pair(max(0, i - ranges[i]), min(n, i + ranges[i])));
        }
        if (intervals.empty()) { return -1; }
        sort(intervals.begin(), intervals.end());

        int ans(0);
        int cur(0), nxt(0), idx(0);
        while (cur < n) {
            if (intervals[idx].first > cur) { return -1; }
            while (idx < intervals.size() && intervals[idx].first <= cur) {
                nxt = max(nxt, intervals[idx].second);
                ++idx;
            }
            ++ans;
            cur = nxt;
        }
        return ans;
    }
};
// @lc code=end

