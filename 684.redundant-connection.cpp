/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int x(0), y(0);
        int n(edges.size());
        vector<int> flags(n, -1);
        for (const vector<int>& edge : edges)
        {
            x = endPoint(flags, edge[0] - 1);
            y = endPoint(flags, edge[1] - 1);
            //cout << x << ' ' << y << endl;
            if (x == y) return edge;
            flags[x] = y; 
        }
        return {};
    }
private:
    int endPoint(const vector<int>& f, int i)
    {
        while (f[i] != -1) i = f[i];
        return i;
    }
};
// @lc code=end

