/*
 * @lc app=leetcode id=1316 lang=cpp
 *
 * [1316] Distinct Echo Substrings
 */

// @lc code=start
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int n(text.size());

        string_view str(text);
        unordered_set<string_view> ust;
        for (int len(1); len <= (n >> 1); ++len) {
            for (int i(0); i + (len << 1) <= n; ++i) {
                if (str.substr(i, len) == str.substr(i + len, len)) { ust.insert(str.substr(i, len)); }
            }
        }
        return ust.size();
    }
};
// @lc code=end

