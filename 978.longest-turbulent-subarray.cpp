/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() < 2) { return A.size(); }
        
        vector<int> dpOdd(A.size(), 1);
        vector<int> dpEven(A.size(), 1);

        int i(0), j(0);
        bool odd = false;
        for (i = 1; i < A.size(); ++i) {
            odd = (i & 1) == 1;
            j = i - 1;
            if ((odd && A[i] > A[j]) || (!odd && A[i] < A[j])) {
                dpOdd[i] = max(dpOdd[i], dpOdd[j] + 1);
            }
            if ((odd && A[i] < A[j]) || (!odd && A[i] > A[j])) {
                dpEven[i] = max(dpEven[i], dpEven[j] + 1);
            }
        }

        int mx(1);
        for (i = 0; i < A.size(); ++i) {
            //cout << dpOdd[i] << '/';
            //cout << dpEven[i] << ' ';
            mx = max(mx, dpOdd[i]);
            mx = max(mx, dpEven[i]);
        }
        //cout << endl;

        return mx;
    }
};
// @lc code=end

