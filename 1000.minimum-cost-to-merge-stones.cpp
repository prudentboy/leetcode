/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n(stones.size());
        if ((n - 1) % (K - 1) > 0) { return -1; }

        vector<int> sums(n + 1, 0);
        for (int i(1); i < n + 1; ++i) { sums[i] = sums[i - 1] + stones[i - 1]; }
        auto calSum = [&](int i, int j) -> int {
            if (j > n || i < 0 || i > j) { return 0; }
            return sums[j + 1] - sums[i];
        };

        int kInf = 1e9;
        vector<vector<int>> memo(n, vector<int>(n, kInf));

        std::function<int(int, int)> calDp;
        calDp = [&](int i, int j) -> int {
            //cout << i << '-' << j << endl;
            if (j - i + 1 < K) { return memo[i][j] = 0; }
            if (memo[i][j] != kInf) { return memo[i][j]; }

            int ans(kInf);
            for (int m(i); m < j; m += K - 1) {
                ans = min(ans, calDp(i, m) + calDp(m + 1, j));
            }
            if ((j - i) % (K - 1) == 0) { ans += calSum(i, j); }
            //cout << i << ' ' << j << ' ' << ans << endl;
            return memo[i][j] = ans;
        };

        return calDp(0, n - 1);
    }
};
// @lc code=end

