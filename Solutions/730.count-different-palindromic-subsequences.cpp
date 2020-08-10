/*
 * @lc app=leetcode id=730 lang=cpp
 *
 * [730] Count Different Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        constexpr int M = 1000000007;
        const int n(S.size());
        vector<vector<int>> idxs(4);
        for (int i(0); i < n; ++i) { idxs[S[i] - 'a'].push_back(i); }

        vector<vector<int>> memo(n, vector<int>(n));

        function<int(int, int)> dp(int beg, int end) {
            if (beg > end) { return 0; }
            if (beg == end) { return 1; }
            if (memo[beg][end] > 0) { return memo[beg][end]; }
            long ret(0);
            for (int i(0); i < 4; ++i) {
                if (idxs[i].empty()) { continue; }
            }
            return memo[beg][end] = ret % M;
        };
        return dp(0, n - 1);
    }
};
// @lc code=end

