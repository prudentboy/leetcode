/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos(speed.size());
        vector<bool> visited(speed.size(), false);
        for (int i(0); i < speed.size(); ++i) {
            pos[i] = {position[i], speed[i]};
        }
        sort(pos.begin(), pos.end());

        int ans(0);
        double tmp(0.0);
        for (int i = pos.size() - 1; i >= 0; --i) {
            if (visited[i]) continue;
            visited[i] = true;
            tmp = (static_cast<double>(target - pos[i].first)) / pos[i].second;
            for (int j = i - 1; j >= 0; --j) {
                if (visited[j]) continue;
                if ((static_cast<double>(target - pos[j].first)) / pos[j].second <= tmp) {
                    visited[j] = true;
                }
            }
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

