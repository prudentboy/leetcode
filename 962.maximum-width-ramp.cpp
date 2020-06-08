/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans(0), n(A.size());
        vector<int> decrease;
        decrease.reserve(n);

        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            if (decrease.empty() || A[decrease.back()] > A[i]) {
                decrease.push_back(i);
            }
        }

        for (i = n - 1; i >= 0; --i) {
            if (decrease.empty()) { break; }
            while (!decrease.empty() && A[i] >= A[decrease.back()]) {
                ans = max(ans, i - decrease.back());
                decrease.pop_back();
            }
        }

        return ans;
    }
};
// @lc code=end

