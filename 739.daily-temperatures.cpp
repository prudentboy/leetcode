/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return {};
        int i(0), n(T.size());
        vector<int> ans(n, 0);
        stack<int> st;
        for (i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && T[st.top()] <= T[i]) st.pop();
            if (st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

