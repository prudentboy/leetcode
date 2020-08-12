/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 */

// @lc code=start
class Solution {
public:
    int minimumDistance(string word) {
        auto dis = [](int c1, int c2) {
            if (c1 == 26 || c2 == 26) { return 0; }
            return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
        };

        const int n(word.size());
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(27, vector<int>(27, -1)));

        function<int(int, int, int)> helper = [&](int idx, int left, int right) -> int {
            if (idx == n) { return 0; }
            if (memo[idx][left][right] != -1) { return memo[idx][left][right]; }
            int nxt(word[idx] - 'A');
            int ret(min(helper(idx + 1, nxt, right) + dis(left, nxt), helper(idx + 1, left, nxt) + dis(right, nxt)));
            return memo[idx][left][right] = ret;
        };

        return helper(0, 26, 26);
    }
};
// @lc code=end

