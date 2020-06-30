/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> relation;
        vector<int> group(N + 1);
        for (auto& dis : dislikes) {
            relation[dis[0]].push_back(dis[1]);
            relation[dis[1]].push_back(dis[0]);
        }
        int i(0), j(0);
        int gx(0), gy(0), tmp(0);
        for (i = 1; i <= N; ++i) { group[i] = i; }
        for (i = 1; i <= N; ++i) {
            if (relation.count(i) == 0) { continue; }
            gx = getGroup(group, i);
            gy = getGroup(group, relation[i][0]);
            if (gx == gy) { return false; }
            for (j = 1; j < relation[i].size(); ++j) {
                tmp = getGroup(group, relation[i][j]);
                if (tmp == gx) { return false; }
                group[tmp] = gy;
            }
        }
        return true;
    }
private:
    int getGroup(const vector<int>& g, int idx) {
        if (g[idx] == idx) { return idx; }
        return getGroup(g, g[idx]); 
    }
};
// @lc code=end

