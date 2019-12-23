/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// @lc code=start
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.size() < 2) return 0;
        
        sort(A.begin(), A.end());
        int i(0), n(A.size());
        int ans(A.back() - A[0]);
        int l(A[0] + K), r(A.back() - K);
        int mn(0), mx(0);
        for (i = 1; i < n; ++i) {
            mn = min(l, A[i] - K);
            mx = max(r, A[i - 1] + K);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};
// @lc code=end

