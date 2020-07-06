/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m(matrix.size()), n(matrix[0].size());
        int ans(0);
        unordered_map<string, int> ump;
        string s1(n, '0'), s2(n, '0');

        int i(0), j(0);
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                s1[j] = matrix[i][j] + '0';
                s2[j] = (matrix[i][j] ^ 1) + '0';
            }
            ++ump[s1];
            if (ump[s1] + ump[s2] > ans) { ans = ump[s1] + ump[s2]; }
        }
        return ans;
    }
};
// @lc code=end

