/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n(graph.size());
        const int all_visited = (1 << n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        queue<pair<int, int>> q;
        for (int i(0); i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int len(0), level(0), state(0);
        pair<int, int> tmp;
        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                q.pop();
                if (tmp.second == all_visited) { return level; }
                for (int node : graph[tmp.first]) {
                    state = tmp.second | (1 << node);
                    if (visited[node][state]) { continue; }
                    visited[node][state] = true;
                    q.push({node, state});
                }
            }
            ++level;
        }
        return -1;
    }
};
// @lc code=end

