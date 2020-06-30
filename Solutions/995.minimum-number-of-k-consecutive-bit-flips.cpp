/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n(A.size());
        int ans(0);

        vector<int> flipFlag(n);
        int flip(0);
        for (int i(0); i < n; ++i) {
            if (i >= K) { flip ^= flipFlag[i - K]; }
            if ((A[i] ^ flip) == 0) {
                if (i > n - K) { return -1; }
                ++ans;
                flip ^= 1;
                flipFlag[i] = 1;
            }
        }

        return ans;
    }
};
// @lc code=end

