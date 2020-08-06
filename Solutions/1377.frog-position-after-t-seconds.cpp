/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n + 1, false);
        visited[1] = true;
        queue<pair<int, double>> q;
        q.push({1, 1.0});
        int level(0), cnt(0);
        bool seen(false);
        vector<double> ans(n + 1, 0.0);
        ans[1] = 1.0;
        while (!q.empty()) {
            if (seen) { return ans[target]; }
            cnt = q.size();
            while (cnt-- > 0) {
                pair<int, double> tmp(q.front());
                //cout << tmp.first << ' ' << tmp.second << endl;
                if (tmp.first == target) { seen = true; }
                q.pop();
                int num(0);
                for (int child : graph[tmp.first]) {
                    if (visited[child]) { continue; }
                    ++num;
                }
                for (int child : graph[tmp.first]) {
                    if (visited[child]) { continue; }
                    q.push({child, tmp.second / num});
                    ans[child] = tmp.second / num;
                    visited[child] = true;
                }
                if (num > 0) { ans[tmp.first] = 0.0; }
            }
            if (++level >= t) { break; }
        }
        return ans[target];
    }
};
// @lc code=end

