/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans(0);

        int i(0), j(0);
        long diff(0);
        int n(A.size());
        vector<unordered_map<int, int>> dp(n);
        for (i = 1; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                diff = (long)A[i] - A[j];
                if (diff > INT_MAX || diff < INT_MIN) { continue; }
                ++dp[i][diff];
                if (dp[j].count(diff) > 0) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff]; 
                }
                //cout << diff << '-' << dp[i][diff] << ';';
            }
            //cout << i << ' ' << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

