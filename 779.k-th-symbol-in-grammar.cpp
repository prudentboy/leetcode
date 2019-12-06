/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int N, int K) {
        int ans(0);
        while (K > 1) {
            ans ^= 1;
            if (K & 1) ++K;
            else K >>= 1;
        }
        return ans;
    }
};
// @lc code=end

