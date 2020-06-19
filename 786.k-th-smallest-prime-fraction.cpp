/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l(0.0), r(1.0), mid(0.0);

        int i(0), j(0);
        int cnt(0);
        double mx(0.0);
        pair<int, int> fraction;

        while (l < r) {
            mid = (l + r) / 2.0;
            cnt = 0;
            j = 1;
            mx = 0.0;
            //cout << l << ' ' << r << ' ' << mid << endl;
            //cout << fraction.first << '/' << fraction.second << endl;
            for (i = 0; i < A.size() - 1; ++i) {
                while (j < A.size() && A[j] * mid < A[i]) { ++j; }
                if (j == A.size()) { break; }
                cnt += (A.size() - j);
                if ((double)A[i] / A[j] > mx) {
                    mx = (double)A[i] / A[j];
                    fraction = {A[i], A[j]};
                } 
            }
            if (cnt == K) {
                return {fraction.first, fraction.second};
            } else if (cnt < K) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return {};
    }
};
// @lc code=end

