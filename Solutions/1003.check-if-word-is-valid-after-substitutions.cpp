/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

// @lc code=start
class Solution {
public:
    bool isValid(string S) {
        string stk;
        for (char c : S) {
            if (c == 'c') {
                if (stk.size() < 2 || stk.back() != 'b') { return false; }
                stk.pop_back();
                if (stk.back() != 'a') { return false; }
                stk.pop_back();
            } else if (c == 'b') {
                if (stk.empty() || stk.back() != 'a') { return false; }
                stk += c;
            } else {
                stk += c;
            }
        }

        return stk.empty();
    }
};
// @lc code=end

