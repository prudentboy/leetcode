/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int n(s.size()), kInf(1000);
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        
        function<int(int, int)> dp = [&](int idx, int k) {
            if (k < 0) { return kInf; }
            if (idx + k >= n) { return 0; }
            if (memo[idx][k] != -1) { return memo[idx][k]; }
            int ret(dp(idx + 1, k - 1));
            int diff(0), cnt(0), same(0);
            for (int j(idx); j < n && diff <= k; ++j) {
                if (s[idx] == s[j]) {
                    ++same;
                    if (same <= 2 || same == 10 || same == 100) { ++cnt; }
                } else { ++diff; }
                ret = min(ret, cnt + dp(j + 1, k - diff));
            }
            return memo[idx][k] = ret;
        };
        
        return dp(0, k);
    }
};
// @lc code=end

