/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m(mat.size()), n(mat[0].size());
        int i(0), j(0), cnt(0);
        vector<pair<int, int>> v(m);
        for (i = 0; i < m; ++i) {
            cnt = 0;
            for (j = 0; j < n; ++j) {
                cnt += mat[i][j];
            }
            v[i] = {i, cnt};
        }
        stable_sort(v.begin(), v.end(), [](const pair<int, int>& l, const pair<int, int>& r) -> bool {
            return l.second < r.second;
        });
        i = 0;
        vector<int> ans(k, -1);
        while (i < k) {
            ans[i] = v[i].first;
            ++i;
        }
        return ans;
    }
};
// @lc code=end

