/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans(0), left(-1), right(-1);
        for (int i(0); i < A.size(); ++i) {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            ans += (right - left);
        }
        return ans;
    }
};
// @lc code=end

