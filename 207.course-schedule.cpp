/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0 || prerequisites.empty() || prerequisites[0].empty()) return true;

        vector<vector<int>> course(numCourses);
        vector<int> ind(numCourses, 0);

        for (const auto& p : prerequisites)
        {
            course[p[1]].push_back(p[0]);
            ++ind[p[0]];
        }

        queue<int> q;
        for (int i(0); i < course.size(); ++i)
        {
            if (ind[i] == 0) q.push(i);
        }

        int now(0);
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            for (const auto& node : course[now])
            {
                --ind[node];
                if (ind[node] == 0) q.push(node);
            }
        }

        for (int i(0); i < ind.size(); ++i) if (ind[i] > 0) return false;
        
        return true;
    }
};

