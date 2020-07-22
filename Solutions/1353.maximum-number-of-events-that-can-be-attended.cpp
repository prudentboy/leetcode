/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& l, const vector<int>& r) {
            if (l[1] == r[1]) { return l[0] < r[0]; }
            return l[1] < r[1];
        });

        int i(0);
        int mn(events[0][0]), mx(events[0][1]);
        for (i = 1; i < events.size(); ++i) {
            mn = min(mn, events[i][0]);
            mx = max(mx, events[i][1]);
        }

        vector<int> days(mx - mn + 1);
        iota(days.begin(), days.end(), mn);
        set<int> valid(days.begin(), days.end());

        int ans(0);
        for (auto& event : events) {
            auto iter(valid.lower_bound(event[0]));
            if (iter == valid.end() || *iter > event[1]) { continue; }
            valid.erase(iter);
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

