/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt(0), tmp(0), n(rooms.size());
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (visited[tmp]) continue;
            visited[tmp] = true;
            ++cnt;
            for (int n : rooms[tmp]) {
                if (visited[n]) continue;
                q.push(n);
            }
        }
        return cnt >= n;
    }
};
// @lc code=end

