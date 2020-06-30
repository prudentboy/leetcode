/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        vector<bool> flag(N + 1, false);

        int i(0), j(0);
        int tmp(0);
        for (i = 0; i < S.size(); ++i) {
            tmp = 0;
            for (j = 0; j < 32 && i + j < S.size() && tmp <= N; ++j) {
                tmp <<= 1;
                tmp += S[i + j] - '0';
                if (tmp > 0 && tmp <= N) { flag[tmp] = true; }
            }
        }

        for (int i(1); i <= N; ++i) {
            if (!flag[i]) { return false; }
        }
        return true;
    }
};
// @lc code=end

