/*
 * @lc app=leetcode id=1253 lang=cpp
 *
 * [1253] Reconstruct a 2-Row Binary Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n(colsum.size());
        vector<vector<int>> ans(2, vector<int>(n));
        
        for (int i(0); i < n; ++i) {
            if (colsum[i] == 0) { continue; }
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                --upper;
                --lower;
            } else if (upper >= lower) {
                --upper;
                ans[0][i] = 1;
            } else {
                --lower;
                ans[1][i] = 1;
            }
        }
        if (upper != 0 || lower != 0) { return {}; }

        return ans;
    }
};
// @lc code=end

