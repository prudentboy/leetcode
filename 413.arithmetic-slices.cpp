/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;

        int ans(0);
        int n(A.size());
        int i(0), j(1), d(A[1] - A[0]), len(1);

        for (i = 1; i < n; ++i)
        {
            if (A[i] - A[i - 1] == d) ++len;
            else
            {
                d = A[i] - A[i - 1];
                if (len >= 3) ans += ((len - 1) * (len - 2) >> 1);
                len = 2;
            }
            //cout << i << ' ' << d << ' ' << len << ' ' << ans << endl;
        }
        if (len >= 3) ans += ((len - 1) * (len - 2) >> 1);
        return ans;
    }
};
// @lc code=end

