/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution {
public:
    int strangePrinter(string s) {
        int n(s.size());
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return strangePrinter(s, 0, n - 1, memo);
    }
private:
    int strangePrinter(const string& s, int beg, int end, vector<vector<int>>& memo) {
        if (beg < 0 || end >= s.size() || beg > end) { return 0; }
        if (beg == end) { return 1; }
        if (memo[beg][end] > 0) { return memo[beg][end]; }

        int ans(strangePrinter(s, beg + 1, end, memo) + 1);

        for (int i(beg + 1); i <= end; ++i) {
            if (s[i] == s[beg]) { ans = min(ans, strangePrinter(s, beg + 1, i, memo) + strangePrinter(s, i + 1, end, memo)); }
        }

        return memo[beg][end] = ans;
    }
};
// @lc code=end

