/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        for (char c : S) {
            if (st.empty() || c == '(' || st.top() != '(') {
                st.push(c);
            } else { st.pop(); }
        }
        return st.size();
    }
};
// @lc code=end

