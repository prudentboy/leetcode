/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n(target.size()), m(1 << n);
        vector<int> dp(m, -1);
        dp[0] = 0;

        int i(0), j(0), cur(0);
        for (i = 0; i < m; ++i) {
            if (dp[i] == -1) { continue; }
            for (const string& str : stickers) {
                cur = i;
                for (char c : str) {
                    for (j = 0; j < n; ++j) {
                        if (target[j] == c && ((cur >> j) & 1) == 0) {
                            cur |= 1 << j;
                            break;
                        }
                    }
                }
                dp[cur] = dp[cur] == -1 ? dp[i] + 1 : min(dp[cur], dp[i] + 1);
                // cout << i << ' ' << cur << ' ' << dp[cur] << endl;
            }
        }

        return dp[m - 1];
    }
};
// @lc code=end

