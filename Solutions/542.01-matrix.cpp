/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {{}};
        int m(matrix.size()), n(matrix[0].size());
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        int cnt(0), now(1);
        set<pair<int, int>> edge, tmp;
        for (int i(0); i < m; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    edge.insert({i, j});
                    ans[i][j] = 0;
                    ++cnt;
                }
            }
        }
        while (cnt < m * n)
        {
            for (const auto& p : edge)
            {
                if (p.first > 0 && ans[p.first - 1][p.second] > now) {++cnt;ans[p.first - 1][p.second] = now;tmp.insert({p.first - 1, p.second});}
                if (p.first < m - 1 && ans[p.first + 1][p.second] > now) {++cnt;ans[p.first + 1][p.second] = now;tmp.insert({p.first + 1, p.second});}
                if (p.second > 0 && ans[p.first][p.second - 1] > now) {++cnt;ans[p.first][p.second - 1] = now;tmp.insert({p.first, p.second - 1});}
                if (p.second < n - 1 && ans[p.first][p.second + 1] > now) {++cnt;ans[p.first][p.second + 1] = now;tmp.insert({p.first, p.second + 1});}
            }
            ++now;
            edge = tmp;
        }
        return ans;
    }
};
// @lc code=end

