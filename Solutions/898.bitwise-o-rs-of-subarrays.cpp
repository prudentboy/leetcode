/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur, tmp, ans;
        for (int i(0); i < A.size(); ++i) {
            tmp.clear();
            tmp.insert(A[i]);
            for (int n : cur) tmp.insert(n | A[i]);
            cur.clear();
            cur = tmp;
            for (int n : cur) ans.insert(n);
        }
        return ans.size();
    }
};
// @lc code=end

