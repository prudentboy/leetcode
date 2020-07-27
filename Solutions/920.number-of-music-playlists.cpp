/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        const int M = 1000000007;

        vector<vector<long long int>> dp(L + 1, vector<long long int>(N + 1, 0));
        dp[0][0] = 1;
        int i(0), j(0);
        for (i = 1; i <= L; ++i) {
            for (j = 1; j <= min(i, N); ++j) {
                dp[i][j] = dp[i - 1][j - 1] * (N - j + 1) + dp[i - 1][j] * max(j - K, 0);
                dp[i][j] %= M;
            }
        }

        return dp[L][N];
    }
};
// @lc code=end

