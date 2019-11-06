/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int m(matrix.size()), n(matrix[0].size());
        vector<vector<int>> flags(m, vector<int>(n, 0));

        vector<vector<bool>> pacv(m, vector<bool>(n, false)), atlv(pacv);
        queue<pair<int, int>> pacq, atlq;
        int i(0), j(0);
        for (i = 0; i < m; ++i)
        {
            flags[i][0] |= 1;
            pacv[i][0] = true;
            pacq.push({i, 0});
            flags[i][n - 1] |= 2;
            atlv[i][n - 1] = true;
            atlq.push({i, n - 1});
        }
        for (j = 0; j < n; ++j)
        {
            flags[0][j] |= 1;
            pacv[0][j] = true;
            pacq.push({0, j});
            flags[m - 1][j] |= 2;
            atlv[m - 1][j] = true;
            atlq.push({m - 1, j});
        }
        //printVV(flags);

        calWaterFlow(matrix, pacv, pacq, flags);
        //printVV(flags);
        calWaterFlow(matrix, atlv, atlq, flags);
        //printVV(flags);

        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (flags[i][j] == 3) ans.push_back({i,j});
            }
        }

        return ans;
    }
private:
    void calWaterFlow(const vector<vector<int>>& matrix, vector<vector<bool>>& v, queue<pair<int, int>>& q, vector<vector<int>>& flags)
    {
        int m(matrix.size()), n(matrix[0].size());
        int i(0), j(0);
        pair<int, int> tmp;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            i = tmp.first;
            j = tmp.second;
            if (i > 0 && !v[i - 1][j] && matrix[i - 1][j] >= matrix[i][j])
            {
                v[i - 1][j] = true;
                flags[i - 1][j] |= flags[i][j];
                q.push({i - 1, j});
            }
            if (j > 0 && !v[i][j - 1] && matrix[i][j - 1] >= matrix[i][j])
            {
                v[i][j - 1] = true;
                flags[i][j - 1] |= flags[i][j];
                q.push({i, j - 1});
            }
            if (i < m - 1 && !v[i + 1][j] && matrix[i + 1][j] >= matrix[i][j])
            {
                v[i + 1][j] = true;
                flags[i + 1][j] |= flags[i][j];
                q.push({i + 1, j});
            }
            if (j < n - 1 && !v[i][j + 1] && matrix[i][j + 1] >= matrix[i][j])
            {
                v[i][j + 1] = true;
                flags[i][j + 1] |= flags[i][j];
                q.push({i, j + 1});
            }
        }
    }
    void printVV(const vector<vector<int>>& vv)
    {
        int m(vv.size()), n(vv[0].size());
        int i(0), j(0);
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                cout << vv[i][j] << ' ';
            }
            cout << endl;
        }
    }
};
// @lc code=end

