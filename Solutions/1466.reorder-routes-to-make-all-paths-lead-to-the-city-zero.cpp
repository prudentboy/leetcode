/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> path(n);
        for (auto& con : connections) {
            path[con[0]].push_back(-con[1]);
            path[con[1]].push_back(con[0]);
        }

        vector<bool> visited(n, false);
        int ans(0);
        queue<int> q({0});
        visited[0] = true;
        while (!q.empty()) {
            int tmp(q.front());
            q.pop();
            for (int neighbor : path[tmp]) {
                if (visited[abs(neighbor)]) { continue; }
                if (neighbor < 0) { ++ans; }
                q.push(abs(neighbor));
                visited[abs(neighbor)] = true;
            }
        }

        return ans;
    }
};
// @lc code=end

