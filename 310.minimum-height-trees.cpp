/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0,1};
        
        vector<int> ans;
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        
        for (const auto& edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        int i(0);
        for (i = 0; i < n; ++i)
        {
            if (graph[i].size() == 1) q.push(i);
        }
        
        int len(0), tmp(0);
        while (n > 2)
        {
            n -= q.size();
            len = q.size();
            //cout << n << ' ' << len << endl;
            while (len-- > 0)
            {
                tmp = q.front();
                q.pop();
                for (const auto& a : graph[tmp])
                {
                    graph[a].erase(tmp);
                    if (graph[a].size() == 1) q.push(a);
                }
            }
        }
        
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};
// @lc code=end

