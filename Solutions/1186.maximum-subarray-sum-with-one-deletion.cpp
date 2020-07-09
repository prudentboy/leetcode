/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n(arr.size()), mx(arr[0]);
        int i(0);
        for (i = 1; i < n; ++i) { mx = max(mx, arr[i]); }
        if (mx <= 0) { return mx; }

        int noDelMx(0), oneDelMx(0), ans(0);
        for (int num : arr) {
            oneDelMx = max(oneDelMx + num, noDelMx);
            noDelMx += num;
            if (oneDelMx < 0) { oneDelMx = 0; }
            if (noDelMx < 0) { noDelMx = 0; }
            ans = max(ans, oneDelMx);
            ans = max(ans, noDelMx);
        }
        return ans;
    }
};
// @lc code=end

