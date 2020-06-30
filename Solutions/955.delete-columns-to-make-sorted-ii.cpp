/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans(0);
        int m(A.size()), n(A[0].size());

        vector<bool> ok(m, false);

        int i(0), j(0);
        bool flag;
        for (i = 0; i < n; ++i) {
            flag = true;
            for (j = 0; j < m - 1; ++j) {
                if (!ok[j] && A[j][i] > A[j + 1][i]) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                ++ans;
            } else {
                for (j = 0; j < m - 1; ++j) {
                    if (!ok[j] && A[j][i] < A[j + 1][i]) {
                        ok[j] = true;
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

