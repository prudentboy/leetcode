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

        vector<vector<int>> memo(n + 1, vector<int>(n + 1));

        function<int(int, int)> dp = [&](int beg, int end) {
            if (beg >= end) { return 0; }
            if (memo[beg][end] > 0) { return memo[beg][end]; }
            long ret(0);
            for (int i(0); i < 4; ++i) {
                if (idxs[i].empty()) { continue; }
                auto nbeg(lower_bound(idxs[i].begin(), idxs[i].end(), beg));
                auto nend(lower_bound(idxs[i].begin(), idxs[i].end(), end) - 1);
                if (nbeg == idxs[i].end() || *nbeg >= end) { continue; }
                ++ret;
                if (nbeg != nend) { ++ret; }
                ret += dp(*nbeg + 1, *nend);
            }
            return memo[beg][end] = ret % M;
        };
        return dp(0, n);
    }
};
// @lc code=end

