/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        ans.reserve(s.size());
        for (int i(0); i < s.size(); ++i) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                ans.push_back('a' + (s[i] - '0') * 10 + s[i + 1] - '0' - 1);
                i += 2;
            } else {
                ans.push_back('a' + s[i] - '0' - 1);
            }
        }
        return ans;
    }
};
// @lc code=end

