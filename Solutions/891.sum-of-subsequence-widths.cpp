/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */

// @lc code=start
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n(A.size());
        constexpr int M = 1000000007;
        long long int ans(0);
        long long int coef(1);
        sort(A.begin(), A.end());
        for (int i(0); i < A.size(); ++i) {
            ans += coef * (A[i] - A[n - 1 - i]);
            ans %= M;
            coef <<= 1;
            coef %= M;
            //cout << ans << ' ' << coef << endl;
        }
        return (ans + M) % M;
    }
};
// @lc code=end

