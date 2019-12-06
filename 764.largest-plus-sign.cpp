/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> mPos(N, vector<int>(N, 0)), visited(mPos);
        for (auto& mine : mines) mPos[mine[0]][mine[1]] = 1;
        int ans(0);
        int i(0), j(0);
        for (i = 0; i < N; ++i)
        {
            for (j = 0; j < N; ++j) culMax(i, j, N, visited, mPos, ans);
        }
        return ans;
    }
private:
    void culMax(int x, int y, const int N, vector<vector<int>>& s, const vector<vector<int>>& m, int& ans) {
        if (s[x][y] > 0) return;
        if (x + 1 <= ans || y + 1 <= ans || N - x <= ans || N - y <= ans) return;
        if (m[x][y] > 0) return;
        int cnt(1);
        for (int k = 1; ; ++k) {
            if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N) break;
            if (m[x - k][y] || m[x + k][y] || m[x][y - k] || m[x][y + k]) break;
            ++cnt;
        }
        ans = max(cnt, ans);
        s[x][y] = 1;
    }
};
// @lc code=end

