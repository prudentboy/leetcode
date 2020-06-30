/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m(A.size()), n(A[0].size());
        
        int i(0), j(0);
        queue<pair<int, int>> q;
        for (j = 1; j < n - 1; ++j) {
            if (A[0][j] == 1) {
                A[0][j] = 2;
                q.push({0, j});
            }
            if (m > 1 && A[m - 1][j] == 1) {
                A[m - 1][j] = 2;
                q.push({m - 1, j});
            }
        }
        for (i = 0; i < m; ++i) {
            if (A[i][0] == 1) {
                A[i][0] = 2;
                q.push({i, 0});
            }
            if (n > 1 && A[i][n - 1] == 1) {
                A[i][n - 1] = 2;
                q.push({i, n - 1});
            }
        }

        const vector<vector<int>> direct({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        pair<int, int> tmp;
        int nextX(0), nextY(0);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            for (i = 0; i < 4; ++i) {
                nextX = tmp.first + direct[i][0];
                nextY = tmp.second + direct[i][1];
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) { continue; }
                if (A[nextX][nextY] != 1) { continue; }
                q.push({nextX, nextY});
                A[nextX][nextY] = 2;
            }
        }

        int ans(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (A[i][j] == 1) { ++ans; }
            }
        }
        return ans;
    }
};
// @lc code=end

