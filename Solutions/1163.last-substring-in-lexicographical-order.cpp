/*
 * @lc app=leetcode id=1163 lang=cpp
 *
 * [1163] Last Substring in Lexicographical Order
 */

// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        char mx(0);
        for (char c : s) { mx = max(mx, c); }
        string_view str(s), ans;
        for (int i(0); i < str.size(); ++i) {
            if (s[i] == mx && str.substr(i) > ans) { ans = str.substr(i); }
        }
        return string(ans);
    }
};
// @lc code=end

