/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
public:
    int countVowelPermutation(int n) {
        const int M = 1000000007;
        long cntA(1), cntE(1), cntI(1), cntO(1), cntU(1);
        long preA(1), preE(1), preI(1), preO(1), preU(1);
        while (--n > 0) {
            cntA = preE + preI + preU;
            cntE = preA + preI;
            cntI = preE + preO;
            cntO = preI;
            cntU = preI + preO;
            preA = cntA % M;
            preE = cntE % M;
            preI = cntI % M;
            preO = cntO % M;
            preU = cntU % M;
        }
        return (cntA + cntE + cntI + cntO + cntU) % M;
    }
};
// @lc code=end

