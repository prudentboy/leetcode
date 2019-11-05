/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return {};

        vector<int> ans(intervals.size(), -1);
        multimap<int, int> m;
        int i(0);
        for (i = 0; i < intervals.size(); ++i) m.insert(make_pair(intervals[i][0], i));

        std::multimap<int, int>::iterator it;
        for (i = 0; i < ans.size(); ++i)
        {
            it = m.lower_bound(intervals[i][1]);
            if (it != m.end()) ans[i] = it->second;
        }

        return ans;
    }
};
// @lc code=end

