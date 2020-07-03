/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int n(s.size());
        if (n == 2) { return s.front() == 0 + s.back() == 1; }
        vector<int> zrCnts(n);

        int ans(0);
        int i(0), cnt(0);
        for (i = 0; i < n; ++i) {
            if (s[i] == '0') { ++cnt; }
            zrCnts[i] = cnt;
        }
        cnt = 0;
        for (i = n - 1; i >= 0; --i) {
            if (s[i] == '1') { ++cnt; }
            zrCnts[i] += cnt;

            if (i < n - 1 && i > 0) ans = max(ans, zrCnts[i]);
        }

        return ans;
    }
};
// @lc code=end

