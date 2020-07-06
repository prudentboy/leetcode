/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> paths(n);
        for (auto& edge : edges) {
            paths[edge[0]].push_back(edge[1]);
            paths[edge[1]].push_back(edge[0]);
        }

        int ans(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        
        function<bool(int)> dfs = [&](int v) -> bool {
            bool flag = hasApple[v];
            for (int child : paths[v]) {
                if (visited[child]) { continue; }
                visited[child] = true;
                if (dfs(child)) { flag = true; }
            }
            if (v > 0 && flag) { ans += 2; }
            return flag;
        };
        dfs(0);

        return ans;
    }
};
// @lc code=end

