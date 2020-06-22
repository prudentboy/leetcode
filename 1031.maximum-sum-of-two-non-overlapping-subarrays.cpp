/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n(A.size());
        
        vector<int> sums(n + 1, 0);
        for (int i(1); i <= n; ++i) { sums[i] = sums[i - 1] + A[i - 1]; }

        int mx(0), ans(0);
        for (int i(0); i + L + M - 1 < n; ++i) {
            mx = max(mx, calSum(i, i + L - 1, sums));
            ans = max(ans, mx + calSum(i + L, i + L + M - 1, sums));
            //cout << mx << ' ' << ans << endl;
        }
        mx = 0;
        for (int i(n - L); i - M >= 0; --i) {
            mx = max(mx, calSum(i, i + L - 1, sums));
            ans = max(ans, mx + calSum(i - M, i - 1, sums));
            //cout << mx << ' ' << ans << endl;
        }

        return ans;
    }
private:
    int calSum(int i, int j, const vector<int>& sums) {
        //cout << i << '-' << j << endl;
        if (i < 0 || j >= sums.size() - 1 || i > j) { return 0; }
        return sums[j + 1] - sums[i];
    }
};
// @lc code=end

