/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans(0), maxCnt(0), start(0), end(0);
        array<int, 26> cnts = {0};
        for (end = 0; end < s.size(); ++end)
        {
            maxCnt = max(maxCnt, ++cnts[s[end] - 'A']);
            while (end - start + 1 - maxCnt > k)
            {
                --cnts[s[start] - 'A'];
                ++start;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
// @lc code=end

