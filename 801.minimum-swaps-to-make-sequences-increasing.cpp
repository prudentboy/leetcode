/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int preSwap(1), preKeep(0), nowSwap(INT_MAX), nowKeep(INT_MAX);
        for (int i(1); i < A.size(); ++i) {
            nowSwap = INT_MAX;
            nowKeep = INT_MAX;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                nowKeep = min(nowKeep, preKeep);
                nowSwap = min(nowSwap, preSwap + 1);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                nowKeep = min(nowKeep, preSwap);
                nowSwap = min(nowSwap, preKeep + 1);
            }
            preSwap = nowSwap;
            preKeep = nowKeep;
        }
        return min(nowSwap, nowKeep);
    }
};
// @lc code=end

