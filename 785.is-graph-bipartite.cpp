/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n(graph.size());
        vector<int> flags(n, 0);
        for (int i(0); i < graph.size(); ++i)
        {
            if (flags[i] != 0) continue;
            if (!validChecker(graph, flags, i, 1)) return false;
        }
        return true;
    }
private:
    bool validChecker(const vector<vector<int>>& g, vector<int>& f, int i, int color)
    {
        if (f[i] != 0) return f[i] == color;
        f[i] = color;
        for (const int n : g[i])
            if (!validChecker(g, f, n, -color)) return false;
        return true;
    }
};
// @lc code=end

