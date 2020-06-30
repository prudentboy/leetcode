/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S.empty()) { return 0; }
        return scoreOfParentheses(S, 0, S.size() - 1);
    }
private:
    int scoreOfParentheses(const string& S, int b, int e) {
        if (b >= e) return 0;
        if (b + 1 == e) return 1;
        int i(0), cnt(0);
        for (i = b; i <= e; ++i) {
            if (S[i] == '(') ++cnt;
            else if (S[i] == ')') --cnt;
            if (cnt == 0) break;
        }
        if (i == e) { return scoreOfParentheses(S, b + 1, e - 1) << 1; }
        if (i == b + 1) { return scoreOfParentheses(S, b + 2, e) + 1; }
        return (scoreOfParentheses(S, b + 1, i - 1) << 1) + scoreOfParentheses(S, i + 1, e);
    }
};
// @lc code=end

