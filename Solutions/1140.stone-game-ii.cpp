/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n(piles.size());
        vector<int> prefixSum(n + 1);
        for (int i(0); i < n; ++i) { prefixSum[i + 1] = piles[i] + prefixSum[i]; }

        unordered_map<int, int> memo;
        function<int(int, int)> solveGame = [&](int idx, int M) {
            if (n - idx <= (M << 1)) { return prefixSum[n] - prefixSum[idx]; }
            int key(idx * 1000 + M);
            if (memo.count(key) != 0) { return memo[key]; }

            int delta(INT_MIN);
            for (int i(1); i <= (M << 1); ++i) { delta = max(delta, prefixSum[idx + i] - prefixSum[idx] - solveGame(idx + i, max(i, M))); }
            //cout << idx << ' ' << M << ' ' << delta << endl;
            return memo[key] = delta;
        };

        return (prefixSum[n] + solveGame(0, 1)) >> 1;
    }
};
// @lc code=end

