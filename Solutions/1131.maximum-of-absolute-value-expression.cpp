/*
 * @lc app=leetcode id=1131 lang=cpp
 *
 * [1131] Maximum of Absolute Value Expression
 */

// @lc code=start
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n(arr1.size());

        int i(0), j(0);
        vector<int> mxArr(8, INT_MIN);

        for (i = 0; i < n; ++i) {
            mxArr[0] = max(mxArr[0], 0 + arr1[i] + arr2[i] + i); 
            mxArr[1] = max(mxArr[1], 0 + arr1[i] + arr2[i] - i); 
            mxArr[2] = max(mxArr[2], 0 + arr1[i] - arr2[i] + i); 
            mxArr[3] = max(mxArr[3], 0 + arr1[i] - arr2[i] - i); 
            mxArr[4] = max(mxArr[4], 0 - arr1[i] + arr2[i] + i); 
            mxArr[5] = max(mxArr[5], 0 - arr1[i] + arr2[i] - i); 
            mxArr[6] = max(mxArr[6], 0 - arr1[i] - arr2[i] + i); 
            mxArr[7] = max(mxArr[7], 0 - arr1[i] - arr2[i] - i); 
        }

        int ans(0);
        for (i = 0; i < 4; ++i) {
            ans = max(ans, mxArr[i] + mxArr[7 - i]);
        }

        return ans;
    }
};
// @lc code=end

