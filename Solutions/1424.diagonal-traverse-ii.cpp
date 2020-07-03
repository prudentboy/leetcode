/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m(nums.size()), n(0);
        int i(0), j(0), cnt(0);

        vector<vector<int>> diag;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < nums[i].size(); ++j) {
                if (i + j >= diag.size()) { diag.push_back({}); }
                diag[i + j].push_back(nums[i][j]);
                ++cnt;
            }
        }

        vector<int> ans(cnt);
        int k(0);
        for (int i(0); i < diag.size(); ++i) {
            for (j = diag[i].size() - 1; j >= 0; --j) { ans[k++] = diag[i][j]; }
        }

        return ans;
    }
};
// @lc code=end

