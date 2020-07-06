/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        stack<unsigned int> stk;
        for (int i(A.size() - 1); i >= 0; --i) {
            if (stk.empty()) {
                stk.push(i);
                continue;
            }
            if (A[i] < A[stk.top()]) { 
                stk.push(i);
            } else if (A[i] == A[stk.top()]) {
                stk.pop();
                stk.push(i);
            } else {
                int idx(0);
                while (!stk.empty() && A[i] > A[stk.top()]) {
                    idx = stk.top();
                    stk.pop();
                }
                swap(A[idx], A[i]);
                break;
            }
        }
        return A;
    }
};
// @lc code=end

