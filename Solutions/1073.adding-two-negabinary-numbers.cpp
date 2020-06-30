/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i(arr1.size() - 1), j(arr2.size() - 1), carry(0), tmp(0);
        while (i >= 0 || j >= 0 || carry != 0) {
            tmp = carry;
            if (i >= 0) { tmp += arr1[i--]; }
            if (j >= 0) { tmp += arr2[j--]; }
            ans.push_back(tmp & 1);
            carry = -(tmp >> 1);
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

