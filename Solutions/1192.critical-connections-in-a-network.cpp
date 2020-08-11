/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int t(0);
        vector<int> ts(n, -1), mn(n, -1);
        vector<vector<int>> ans;

        function<void(int, int)> tarjan = [&](int cur, int par) {
            ts[cur] = mn[cur] = ++t;
            for (int nxt : graph[cur]) {
                if (mn[nxt] != -1) {
                    if (nxt != par) { mn[cur] = min(mn[cur], ts[nxt]); }
                } else {
                    tarjan(nxt, cur);
                    mn[cur] = min(mn[cur], mn[nxt]);
                    if (ts[cur] < mn[nxt]) { ans.push_back({cur, nxt}); }
                }
            }
        };

        tarjan(0, -1);
        return ans;
    }
};
// @lc code=end

