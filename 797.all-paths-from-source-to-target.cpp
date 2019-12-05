/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.empty() || graph[0].empty()) {
            return {};
        }
        
        vector<vector<int>> ans;
        vector<int> cur;
        helper(graph, 0, cur, ans);
        return ans;
    }
private:
    void helper(const vector<vector<int>>& graph, int idx, vector<int> cur, vector<vector<int>>& ans) {
        cur.push_back(idx);
        if (idx == graph.size() - 1) {
            ans.push_back(cur);
            return;
        }
        for (int n : graph[idx]) {
            helper(graph, n, cur, ans);
        }
    }
};
// @lc code=end

