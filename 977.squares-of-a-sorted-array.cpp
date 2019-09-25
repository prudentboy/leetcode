/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return A;

        vector<int> ans(A.size(), 0);
        int sep(0), i(0), j(0), k(0);
        for (; i < A.size(); ++i) 
        {
            if (A[i] >= 0)
            {
                sep = i;
                break;
            }
        }
        i = sep - 1;
        j = sep;
        while (i >= 0 && j < A.size())
        {
            if (A[i] * A[i] < A[j] * A[j])
            {
                ans[k++] = A[i] * A[i];
                --i;
            }
            else
            {
                ans[k++] = A[j] * A[j];
                ++j;
            }
        }
        while (i >= 0)
        {
            ans[k++] = A[i] * A[i];
            --i;
        }
        while (j < A.size())
        {
            ans[k++] = A[j] * A[j];
            ++j;
        }
        return ans;
    }
};

