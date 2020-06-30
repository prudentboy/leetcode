/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int left(0), right(0);
        int i(0), n(s.size());
        for (i = 0; i < n; ++i)
        {
            if (s[i] == '(' || s[i] == '*') ++left;
            else if (s[i] == ')') --left;
            if (left < 0) return false;
        }
        if (left == 0) return true;
        for (i = n - 1; i >= 0; --i)
        {
            if (s[i] == ')' || s[i] == '*') ++right;
            else if (s[i] == '(') --right;
            if (right < 0) return false;
        }
        return right >= 0;
    }
};
// @lc code=end

