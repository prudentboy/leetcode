/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ans(n, -1);
        ans[0] = 0;

        vector<unordered_map<int, vector<int>>> graph(2);
        for (auto& edge : red_edges) { graph[0][edge[0]].push_back(edge[1]); }
        for (auto& edge : blue_edges) { graph[1][edge[0]].push_back(edge[1]); }
        
        auto getShortestPathLen = [&](bool useRed) {
            vector<int> visited(n);
            visited[0] = 3;
            queue<int> q;
            q.push(0);
            int tmp(0), level(0), len(0), edgeType(0);
            while (!q.empty()) {
                len = q.size();
                while (len-- > 0) {
                    tmp = q.front();
                    //cout << tmp << ' ' << visited[tmp] << ' ' << ans[tmp] << endl;
                    q.pop();
                    if (ans[tmp] == -1 || level < ans[tmp]) { ans[tmp] = level; }
                    edgeType = useRed ? 0 : 1;
                    auto& ump = graph[edgeType];
                    for (int nxt : ump[tmp]) {
                        //cout << nxt << ' ' << visited[nxt] << ' ' << edgeType << endl;
                        if ((visited[nxt] & (1 << edgeType)) > 0) { continue; }
                        visited[nxt] |= (1 << edgeType);
                        //cout << nxt << endl;
                        q.push(nxt);
                    }
                }
                ++level;
                useRed = !useRed;
            }
        };
        
        getShortestPathLen(true);
        getShortestPathLen(false);

        return ans;
    }
};
// @lc code=end

