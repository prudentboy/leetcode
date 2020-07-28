/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n(A.front().size());
        vector<int> dp(n, 1);

        for (int i(1); i < n; ++i) {
            for (int j(0); j < i; ++j) {
                bool flag(true);
                for (const string& a : A) {
                    if (a[j] > a[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) { dp[i] = max(dp[i], dp[j] + 1); }
            }
        }

        return A.front().size() - *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

