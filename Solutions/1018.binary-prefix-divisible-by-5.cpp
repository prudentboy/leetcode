/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), false);

        int tmp(0);
        for (int i(0); i < A.size(); ++i)
        {
            tmp <<= 1;
            tmp += A[i];
            tmp %= 5;
            if (tmp % 5 == 0) ans[i] = true;
        }

        return ans;
    }
};
// @lc code=end

