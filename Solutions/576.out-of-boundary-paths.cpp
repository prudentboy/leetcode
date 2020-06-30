/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0 || i < 0 || i >= m || j < 0 || j >= n) return 0;
        long long int ans(0);
        vector<vector<vector<long long int>>> grids(2, vector<vector<long long int>>(m, vector<long long int>(n, 0)));
        int index(0);
        grids[0][i][j] = 1;
        while (N-- > 0)
        {
            ans += cntOutNum(grids[index]);
            ans %= 1000000007;
            updateGrid(grids[index], grids[(index + 1) % 2]);
            index = (index + 1) % 2;
        }
        return ans;
    }
private:
    long long int cntOutNum(const vector<vector<long long int>>& g)
    {
        long long int ans(0);
        int i(0), j(0);
        size_t m(g.size()), n(g[0].size());
        for (i = 0; i < m; ++i) ans += g[i][0] + g[i][n - 1];
        for (j = 0; j < n; ++j) ans += g[0][j] + g[m - 1][j];
        return ans;
    }
    void updateGrid(const vector<vector<long long int>>& ori, vector<vector<long long int>>& now)
    {
        int i(0), j(0);
        int m(ori.size()), n(ori[0].size());
        long long int tmp(0);
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                tmp = 0;
                if (i > 0) tmp += ori[i - 1][j];
                if (i + 1 < m) tmp += ori[i + 1][j];
                if (j > 0) tmp += ori[i][j - 1];
                if (j + 1 < n) tmp += ori[i][j + 1];
                now[i][j] = tmp % 1000000007; 
            }
        }
    }
};
// @lc code=end

