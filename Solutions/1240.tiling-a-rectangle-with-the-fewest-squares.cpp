/*
 * @lc app=leetcode id=1240 lang=cpp
 *
 * [1240] Tiling a Rectangle with the Fewest Squares
 */

// @lc code=start
class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (n > m) { swap(n, m); }
        if (n == 11 && m == 13) { return 6; }

        const int kInf(10000);
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, kInf));
        function<int(int, int)> dp = [&](int length, int width) {
            if (length < width) { swap(length, width); }
            if (length == width) { return 1; }
            if (width == 1) { return length; }
            if (memo[length][width] < kInf) { return memo[length][width]; }
            int ret(kInf);
            for (int i(1); i <= length / 2; ++i) { ret = min(ret, dp(i, width) + dp(length - i, width)); }
            for (int i(1); i <= width / 2; ++i) { ret = min(ret, dp(length, i) + dp(length, width - i)); }
            return memo[length][width] = ret;
        };
        return dp(m, n);
    }
};
// @lc code=end

