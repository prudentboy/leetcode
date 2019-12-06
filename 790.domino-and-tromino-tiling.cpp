/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
    int numTilings(int N) {
        const int mod = 1000000007;
        if (N < 2) return 1;
        if (N == 2) return 2;
        if (N == 3) return 5;
        int minus3(1), minus2(2), minus1(5), ans(0);
        for (int i = 4; i <= N; ++i) {
            ans = (2 * minus1 % mod + minus3) % mod;
            minus3 = minus2;
            minus2 = minus1;
            minus1 = ans; 
        }
        return ans;
    }
};
// @lc code=end

