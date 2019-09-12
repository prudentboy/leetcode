/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans(0);

        stack<int> s;
        int pre(0), after(0);
        for (const string& str : tokens)
        {
            if (isOperator(str))
            {
                after = s.top();
                s.pop();
                pre = s.top();
                s.pop();
                s.push(computeOperator(pre, after, str)); 
            }
            else
            {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
private:
    inline bool isOperator(const string& s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    inline int computeOperator(int pre, int after, const string& opr)
    {
        if (opr == "+") return pre + after;
        if (opr == "-") return pre - after;
        if (opr == "*") return pre * after;
        if (opr == "/") return pre / after;
        return 0;
    }
};

