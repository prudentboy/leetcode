/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans(0);
        int n(s.size());
        unordered_map<string_view, int> ump;

        auto update = [&](int len) {
            int i(0), j(0), cnt(0);
            vector<int> cnts(26);
            for (i = 0; i < n; ++i) {
                if (++cnts[s[i] - 'a'] == 1) { ++cnt; }
                if (i - j + 1 < len) { continue; }
                if (i - j + 1 == len) {
                    if (cnt <= maxLetters) { ans = max(ans, ++ump[s.substr(j, len)]); }
                    if (--cnts[s[j++] - 'a'] == 0) { --cnt; }
                }
            }
        };

        //for (int i(minSize); i <= maxSize; ++i) { update(i); }
        update(minSize);

        return ans;
    }
};
// @lc code=end

