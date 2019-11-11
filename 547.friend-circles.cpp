/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;

        int n(M.size());
        vector<bool> flag(n, false);

        int ans(0);
        int i(0), j(0);
        for (i = 0; i < n; ++i)
        {
            if (!flag[i])
            {
                updateFlag(M, flag, i);
                ++ans;
            }
            //cout << i << ' ' << ans << endl;
        }
        return ans;
    }
private:
    void updateFlag(const vector<vector<int>>& M, vector<bool>& flag, int i)
    {
        int n(M.size());
        if (i < 0 || i >= n || flag[i]) return;
        flag[i] = true;
        for (int j(0); j < n; ++j)
        {
            if (M[i][j] == 0 || j == i) continue;
            updateFlag(M, flag, j);
        }
    }
};
// @lc code=end

