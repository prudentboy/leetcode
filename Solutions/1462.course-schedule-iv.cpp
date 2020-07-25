/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(n));
        int i(0), j(0), k(0);
        for (i = 0; i < n; ++i) { graph[i][i] = 1; }
        for (auto& pre : prerequisites) { graph[pre[0]][pre[1]] = 1; }
        
        for (k = 0; k < n; ++k) {
            for (i = 0; i < n; ++i) {
                for (j = 0; j < n; ++j) {
                    graph[i][j] |= graph[i][k] & graph[k][j];
                }
            }
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(graph[q[0]][q[1]] == 1);
        }
        return ans;
    }
};
// @lc code=end

