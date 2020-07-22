/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m(connections.size());
        if (m + 1 < n) { return -1; }

        int i(0);
        vector<int> parent(n);
        for (i = 0; i < n; ++i) { parent[i] = i; }

        function<int(int)> find = [&](int idx) {
            if (parent[idx] != idx) { parent[idx] = find(parent[idx]); }
            return parent[idx];
        };

        int x(0), y(0);
        for (auto& con : connections) {
            x = find(con[0]);
            y = find(con[1]);
            parent[x] = y;
        }

        int cnt(0);
        for (i = 0; i < n; ++i) { if (parent[i] == i) {++cnt;} }

        return cnt - 1;
    }
};
// @lc code=end

