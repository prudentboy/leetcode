/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int pos(0), fuel(startFuel), ans(0);
        stations.push_back({target, 0});
        priority_queue<int> pq;
        for (auto& station : stations) {
            while (station[0] > pos + fuel && !pq.empty()) {
                fuel += pq.top();
                pq.pop();
                ++ans;
            }
            if (station[0] > pos + fuel) { return -1; }
            fuel -= station[0] - pos;
            pos = station[0];
            pq.push(station[1]);
        }
        return ans;
    }
};
// @lc code=end

