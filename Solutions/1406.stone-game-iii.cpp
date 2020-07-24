/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const vector<string> results({"Alice", "Bob", "Tie"});

        int n(stoneValue.size());
        vector<int> dp(n, INT_MIN);

        function<int(int)> play = [&](int i) -> int {
            if (i >= n) { return 0; }
            if (dp[i] != INT_MIN) { return dp[i]; }
            int sum(0);
            for (int j(0); j < 3 && i + j < n; ++j) {
                sum += stoneValue[i + j];
                dp[i] = max(dp[i], sum - play(i + j + 1));
            }
            return dp[i];
        };

        play(0);
        int idx(2);
        if (dp[0] > 0) {
            idx = 0;
        } else if (dp[0] < 0) {
            idx = 1;
        }
        return results[idx];
    }
};
// @lc code=end

