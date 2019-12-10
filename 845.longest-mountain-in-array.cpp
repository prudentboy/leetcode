/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans(0);
        int i(1), n(A.size());
        int change(0), len(0);

        while (i < n && A[i] <= A[i - 1]) ++i;
        if (i >= n - 1) return ans;
        change = 1;
        len = 1;
        for (; i < n; ++i) {
            if (A[i] == A[i - 1]) {
                change = 0;
                if (change == 2 && len > 2) ans = max(ans, len);
                len = 0;
            } else if (A[i] > A[i - 1]) {
                if (change == 1) {
                    ++len;
                } else {
                    change = 1;
                    len = 2;
                }
            } else {
                if (change == 0) continue;
                if (change == 1) change = 2;
                ++len;
                ans = max(len, ans);
            }
        }
        return ans;
    }
};
// @lc code=end

