/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int M = 1000000007;
        int ans(0);
        int tmp(0), now(0), left(0), right(0);
        stack<int> st;
        for (int i(0); i <= A.size(); ++i) {
            now = (i == A.size()) ? 0 : A[i];
            while (!st.empty() && A[st.top()] > now) {
                tmp = st.top();
                st.pop();
                if (st.empty()) {
                    left = tmp + 1;
                } else {
                    left = tmp - st.top();
                }
                right = i - tmp;
                ans = (ans + A[tmp] * left * right) % M;
                //cout << ans << endl;
            }
            //cout << i << ' ' << ans << endl;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

