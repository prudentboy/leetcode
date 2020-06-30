/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        double ans(0.0);
        int i(0), j(0), k(0), n(A.size());
        
        int sNow(0);
        vector<int> sum(n, 0);
        for (i = 0; i < n; ++i) {
            sNow += A[i];
            sum[i] = sNow;
            //cout << sum[i] << ' ';
        }
        //cout << endl;
        //cout << "---" << endl;
        
        if (K == 1) return sNow / static_cast<double>(n);
        if (K >= n) return sNow;

        vector<vector<double>> dp(n, vector<double>(K, 0.0));
        for (i = 0; i < n; ++i) {
            dp[i][0] = sum[i] / static_cast<double>(i + 1);
            //cout << i << " 0 " << dp[i][0] << endl;
        }
        for (j = 1; j < K; ++j) {
            for (i = 0; i < n; ++i) {
                if (i <= j) {
                    dp[i][j] = sum[i];
                    continue;
                } else {
                    for (k = 0; k <= i; ++k) dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) / static_cast<double>(i - k));
                }
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[n - 1][K - 1];
    }
};
// @lc code=end

