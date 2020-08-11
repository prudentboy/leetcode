/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 */

// @lc code=start
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        const int m(mat.size()), n(mat[0].size());
        auto pos = [&](int x, int y) { return x * n + y; };

        int start(0);
        for (int i(0); i < m; ++i) {
            for (int j(0); j < n; ++j) {
                if (mat[i][j] == 1) { start |= (1 << pos(i, j)); }
            }
        }

        queue<int> q;
        vector<bool> visited(1 << (m * n), false);
        q.push(start);
        visited[start] = true;

        int ans(0);
        while (!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                int state(q.front());
                q.pop();
                //cout << state << endl;
                if (state == 0) { return ans; }
                for (int i(0); i < m; ++i) {
                    for (int j(0); j < n; ++j) {
                        int newState(state);
                        newState ^= (1 << pos(i, j));
                        if (i > 0) { newState ^= (1 << pos(i - 1, j)); }
                        if (j > 0) { newState ^= (1 << pos(i, j - 1)); }
                        if (i < m - 1) { newState ^= (1 << pos(i + 1, j)); }
                        if (j < n - 1) { newState ^= (1 << pos(i, j + 1)); }
                        if (visited[newState]) { continue; }
                        q.push(newState);
                        visited[newState] = true;
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};
// @lc code=end

