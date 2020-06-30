/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n(A.size());
        vector<unordered_map<int, int>> history(n);

        int ans(0);
        int i(0), j(0), diff(0);
        for (i = 1; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                diff = A[i] - A[j];
                history[i][diff] = max(history[i][diff], max(2, history[j][diff] + 1));
                ans = max(ans, history[i][diff]);
            }
        }

        return ans;
    }
};
// @lc code=end

