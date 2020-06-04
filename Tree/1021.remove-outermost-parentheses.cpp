/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        ans.reserve(S.size());

        int cnt(0);
        for (char c : S) {
            if (cnt == 0) {
                ++cnt;
                continue;
            }
            if (c == '(') {
                ++cnt;
                ans.push_back(c);
            } else if (c == ')') {
                --cnt;
                if (cnt > 0) { ans.push_back(c); }
            }
        }

        return ans;
    }
};
// @lc code=end

