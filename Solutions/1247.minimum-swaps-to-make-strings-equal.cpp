/*
 * @lc app=leetcode id=1247 lang=cpp
 *
 * [1247] Minimum Swaps to Make Strings Equal
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n(s1.size());
        int i(0), xy(0), yx(0);
        for (i = 0; i < n; ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') { ++xy; }
            if (s1[i] == 'y' && s2[i] == 'x') { ++yx; }
        }
        if ((xy + yx) & 1) { return -1; }
        return (xy + 1) / 2 + (yx + 1) / 2;
    }
};
// @lc code=end

