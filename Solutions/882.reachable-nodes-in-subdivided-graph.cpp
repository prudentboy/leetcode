/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */

// @lc code=start
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for (auto& edge : edges) { graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = edge[2]; }

        vector<bool> visited(N, false);
        vector<int> resHp(N, -1);
        priority_queue<pair<int, int>> pq;
        pq.push({M, 0});

        pair<int, int> tmp;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            if (visited[tmp.second]) { continue; }
            visited[tmp.second] = true;
            resHp[tmp.second] = tmp.first;

            for (int i(0); i < N; ++i) {
                if (visited[i] || i == tmp.second || graph[tmp.second][i] == -1 || graph[tmp.second][i] >= tmp.first) { continue; }
                int rest(tmp.first - graph[tmp.second][i] - 1);
                pq.push({rest, i});
            }
        }

        int ans(0);
        for (int i(0); i < N; ++i) { if (resHp[i] >= 0) { ++ans; } }
        for (auto& edge : edges) {
            int left(resHp[edge[0]] < 0 ? 0 : resHp[edge[0]]);
            int right(resHp[edge[1]] < 0 ? 0 : resHp[edge[1]]);
            ans += min(edge[2], left + right);
        }
        /*
        for (int i(0); i < N; ++i) {
            cout << i << ':' << resHp[i] << endl;
            if (resHp[i] == -1) { continue; }
            ++ans;
            for (int j(i + 1); j < N; ++j) {
                if (resHp[j] == -1 || graph[i][j] == -1) { continue; }
                ans += min(graph[i][j], resHp[i] + resHp[j]);
            }
        }
        */
        return ans;
    }
};
// @lc code=end

