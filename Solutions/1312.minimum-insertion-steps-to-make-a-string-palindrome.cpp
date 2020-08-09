/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        const int n(s.size());
        vector<vector<int>> memo(n, vector<int>(n, -1));

        function<int(int, int)> dp = [&](int beg, int end) {
            if (beg >= end) { return 0; }
            if (memo[beg][end] != -1) { return memo[beg][end]; }
            if (s[beg] == s[end]) { return dp(beg + 1, end - 1); }
            return memo[beg][end] = min(dp(beg + 1, end), dp(beg, end - 1)) + 1;
        };
        return dp(0, n - 1);
    }
};
// @lc code=end

