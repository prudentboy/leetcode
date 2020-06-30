/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long int n(A.size()), sum(0), max(0), tmp(0);

        for (int i(0); i < n; ++i)
        {
            sum += A[i];
            tmp += i * A[i];
        }
        max = tmp;

        for (int i(1); i < n; ++i)
        {
            tmp += (sum - n * A[n - i]);
            if (tmp > max) max = tmp;
        }

        return max;
    }
};
// @lc code=end

