/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m(A.size()), n(A[0].size());
        int i(0), j(0), ans(0);
        for (i = 0; i < m; ++i) {
            if (A[i][0] == 0) { flipRow(A[i]); }
        }
        ans += m * (1 << n - 1);
        int cnt(0), b(0);
        for (j = 1; j < n; ++j) {
            cnt = 0;
            b = 1 << n - j - 1;
            for (i = 0; i < m; ++i) {
                if (A[i][j] == 0) ++cnt;
            }
            ans += max(cnt, m - cnt) * b;
        }
        return ans;
    }
private:
    inline void flipRow(vector<int>& v) {
        for (int i(0); i < v.size(); ++i) {
            v[i] = (v[i] == 0) ? 1 : 0;
        }
    }
};
// @lc code=end

