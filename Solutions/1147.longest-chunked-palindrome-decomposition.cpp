/*
 * @lc app=leetcode id=1147 lang=cpp
 *
 * [1147] Longest Chunked Palindrome Decomposition
 */

// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        return helper(text);
    }
private:
    int helper(string_view s) {
        if (s.empty()) { return 0; }
        const int n(s.size());
        for (int i(1); i < n; ++i) {
            if (s.substr(0, i) == s.substr(n - i)) { return 2 + helper(s.substr(i, n - i * 2));}
        }
        return 1;
    }
};
// @lc code=end

