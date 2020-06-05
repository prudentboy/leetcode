/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans(0);
        int i(0), j(0);
        for (i = 0; i < A.size() - 1; ++i) {
            if (A.size() - 1 - i <= ans) { break; }
            for (j = A.size() - 1; j > i + ans; --j) {
                if (A[i] <= A[j]) {
                    ans = max(ans, j - i);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

