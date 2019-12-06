/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.empty()) return true;
        for (int i(0); i < A.size(); ++i) {
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};
// @lc code=end

