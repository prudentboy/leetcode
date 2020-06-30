/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans(0);
        if ((a | b) == c) { return ans; }
        bool x(false), y(false), z(false);
        for (int i = 0; i < 31; ++i) {
            z = (c & (1 << i)) > 0;
            y = (b & (1 << i)) > 0;
            x = (a & (1 << i)) > 0;
            if (z && !x && !y) {
                ++ans;
            } else if (!z) {
                if (x) { ++ans; }
                if (y) { ++ans; }
            }
            //cout << i << ':' << x << '-' << y << '-' << z << endl;
            //cout << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

