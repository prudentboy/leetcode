/*
 * @lc app=leetcode id=1156 lang=cpp
 *
 * [1156] Swap For Longest Repeated Character Substring
 */

// @lc code=start
class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<int>> dp(26, vector<int>(2));

        int i(0), j(0);
        int len0(0), len1(0);

        unordered_map<int, int> ump;
        for (char c : text) { ++ump[c - 'a']; }

        int ans(0);
        for (j = 0; j < 26; ++j) {
            if (ump.count(j) == 0) { continue; }
            len0 = len1 = 0;
            for (i = 0; i < text.size(); ++i) {
                if (text[i] - 'a' == j) {
                    ++len0;
                    ++len1;
                } else {
                    len1 = len0 + 1;
                    len0 = 0;
                }
                dp[j][0] = max(dp[j][0], len0);
                dp[j][1] = max(dp[j][1], len1);
            }
            if (ump[j] < dp[j][1]) { --dp[j][1]; }
            ans = max(ans, max(dp[j][0], dp[j][1]));
            //cout << (char)('a' + j) << ':' << dp[j][0] << ',' << dp[j][1] << endl;
        }

        return ans;
    }
};
// @lc code=end

