/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) return {};

        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> ind(numCourses, 0);
        for (const auto& p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            ++ind[p[0]];
        }

        queue<int> q;
        for (int i(0); i < ind.size(); ++i)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }

        int now(0);
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            ans.push_back(now);
            for (const auto& node : graph[now])
            {
                --ind[node];
                if (ind[node] == 0) q.push(node);
            }
        }

        for (int node : ind)
        {
            if (node > 0)
            {
                return {};
            }
        }

        return ans;
    }
};

