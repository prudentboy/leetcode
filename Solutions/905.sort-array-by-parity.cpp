/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        partition(A.begin(), A.end(), [](int a) {return a % 2 == 0;});
        return A;
    }
};
// @lc code=end

