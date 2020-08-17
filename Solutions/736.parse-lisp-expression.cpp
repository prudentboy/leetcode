/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 */

// @lc code=start
class Solution {
public:
    int evaluate(string expression) {
        return evaluate(expression, {});
    }
private:
    int evaluate(string_view expression, unordered_map<string_view, int> dict) {
        //cout << "evaluate: " << expression << '$' << endl;
        //for (auto& p : dict) { cout << '*' << p.first << ':' << p.second << endl;}
        if (expression.front() == '(') { return evaluate(expression.substr(1, expression.size() - 2), dict); }
        auto it(expression.find_first_of(' '));
        if (it == string::npos) {
            if (expression.front() >= 'a' && expression.front() <= 'z') { return dict[expression]; }
            return stoi(string(expression));
        }
        string_view cmd(expression.substr(0, it));
        if (cmd == "add") {
            int left(0), right(0);
            getTwoValues(expression.substr(it + 1), dict, left, right);
            return left + right;
        } else if (cmd == "mult") {
            int left(0), right(0);
            getTwoValues(expression.substr(it + 1), dict, left, right);
            return left * right;
        } else {
            size_t i(it + 1);
            string_view name;
            while (i != expression.size()) {
                size_t end(i);
                if (expression[i] == '(') {
                    end = getLastIndex(expression, i) + 1;
                    if (end == expression.size()) { return evaluate(expression.substr(i), dict); }
                } else {
                    end = expression.find_first_of(' ', i);
                    if (end == string::npos) { return evaluate(expression.substr(i), dict); }
                }
                //if (end == string::npos || end + 1 == expression.size()) { return evaluate(expression.substr(i), dict); }
                if (name.empty()) {
                    name = expression.substr(i, end - i);
                    //cout << "para: " << name << '$' << endl;
                } else {
                    dict[name] = evaluate(expression.substr(i, end - i), dict);
                    name = "";
                }
                i = end + 1;
            }
        }
        return 0;
    }
    void getTwoValues(string_view expression, unordered_map<string_view, int> dict, int& left, int& right) {
        if (expression.front() == '(') {
            size_t end(getLastIndex(expression, 0));
            left = evaluate(expression.substr(1, end - 1), dict);
            right = evaluate(expression.substr(end + 2), dict);
        } else {
            auto it(expression.find_first_of(' '));
            left = evaluate(expression.substr(0, it), dict);
            right = evaluate(expression.substr(it + 1), dict);
        }
    }
    size_t getLastIndex(string_view expression, size_t beg) {
        int cnt(0);
        for (size_t i(beg); i < expression.size(); ++i) {
            if (expression[i] == '(') {
                ++cnt;
            } else if (expression[i] == ')') {
                if (--cnt == 0) { return i; }
            }
        }
        return expression.size();
    }
};
// @lc code=end

