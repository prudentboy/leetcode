/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        return parse(expression);
    }
private:
    bool parseBoolChar(char c) { return c == 't'; }
    bool parseORExpr(string_view exp) {
        if (exp.front() == '(') { return parseORExpr(exp.substr(1, exp.size() - 2)); }
        int pre(0);
        for (int i(0); i < exp.size(); ++i) {
            if (exp[i] == '!' || exp[i] == '&' || exp[i] == '|') {
                int cnt(0), j(i + 1);
                for (; j < exp.size(); ++j) {
                    if (exp[j] == '(') {
                        ++cnt;
                    } else if (exp[j] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) { break; }
                }
                if (parse(exp.substr(i, j - i + 1))) { return true; }
                i = j + 1;
                if (i < exp.size() && exp[i] == ',') { ++i; }
                pre = i;
            } else if (exp[i] == ',') {
                if (pre < i && parse(exp.substr(pre, i - pre))) { return true; }
                pre = i + 1;
            }
        }
        return pre < exp.size() ? parse(exp.substr(pre)) : false;
    }
    bool parseANDExpr(string_view exp) {
        if (exp.front() == '(') { return parseANDExpr(exp.substr(1, exp.size() - 2)); }
        int pre(0);
        for (int i(0); i < exp.size(); ++i) {
            if (exp[i] == '!' || exp[i] == '&' || exp[i] == '|') {
                int cnt(0), j(i + 1);
                for (; j < exp.size(); ++j) {
                    if (exp[j] == '(') {
                        ++cnt;
                    } else if (exp[j] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) { break; }
                }
                if (!parse(exp.substr(i, j - i + 1))) { return false; }
                i = j + 1;
                if (i < exp.size() && exp[i] == ',') { ++i; }
                pre = i;
            } else if (exp[i] == ',') {
                if (pre < i && !parse(exp.substr(pre, i - pre))) { return false; }
                pre = i + 1;
            }
        }
        return pre < exp.size() ? parse(exp.substr(pre)) : true;
    }
    bool parse(string_view exp) {
        if (exp.size() == 1) { return parseBoolChar(exp.front()); }
        if (exp.front() == '(') { return parse(exp.substr(1, exp.size() - 2)); }
        if (exp.front() == '!') { return !parse(exp.substr(1, exp.size() - 1)); }
        if (exp.front() == '|') { return parseORExpr(exp.substr(1, exp.size() - 1)); }
        if (exp.front() == '&') { return parseANDExpr(exp.substr(1, exp.size() - 1)); }
        return false;
    }
};
// @lc code=end

