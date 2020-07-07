/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> delta(n + 2);
        for (auto& booking : bookings) {
            delta[booking[0]] += booking[2];
            delta[booking[1] + 1] -= booking[2];
        }

        vector<int> ans(n);
        int cur(0);
        for (int i(0); i < n; ++i) {
            cur += delta[i + 1];
            ans[i] = cur;
        }
        return ans;
    }
};
// @lc code=end

