/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const long long int Mode = 1000000007;
        long long int ans(0);
        unordered_map<int, long long int> m;
        sort(A.begin(), A.end());
        int i(0), j(0), n(A.size());
        for (i = 0; i < n; ++i) {
            m[A[i]] = 1;
            for (j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && m.count(A[i] / A[j]) > 0) {
                    m[A[i]] += (m[A[j]] * m[A[i] / A[j]] % Mode);
                    m[A[i]] %= Mode;
                }
            }
            ans += m[A[i]];
            ans %= Mode;
        }
        return ans;
    }
};
// @lc code=end

