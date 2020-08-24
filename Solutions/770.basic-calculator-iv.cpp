/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        const int m(evalvars.size());
        for (int i(0); i < m; ++i) { known_[evalvars[i]] = evalints[i]; }

        Polys ret(basicCalculatorIV(expression));
        return getAnswer(ret);
    }
private:
    using Poly = vector<int>;
    using Polys = map<Poly, int>;
    Polys basicCalculatorIV(const string_view& exp) {
        stack<Polys> pStk;
        stack<char> operatorStk;
        char pre('+');
        operatorStk.push('+');

        for (int i(0); i < exp.size(); ++i) {
            // blank
            if (exp[i] == ' ') { continue; }
            // digit
            if (isdigit(exp[i])) {
                int num(exp[i++] - '0');
                while (i < exp.size() && isdigit(exp[i])) {
                    num *= 10;
                    num += exp[i++] - '0';
                }
                --i;
                cout << num << endl;
                Polys tmp({{}, num});
                if (!operatorStk.empty() && operatorStk.top() == '*') {
                    multi(tmp, pStk.top());
                    operatorStk.pop();
                }
                pStk.push(move(tmp));
                continue;
            }
            // variable
            if (isalpha(exp[i])) {
                int beg(i), len(1);
                while (i < exp.size() && isalpha(exp[i])) {
                    ++i;
                    ++len;
                }
                --i;
                string_view var(exp.substr(beg, len));
                cout << var << endl;
                Polys tmp;
                if (known_.count(var) > 0) {
                    tmp[{}] = known_[var];
                } else {
                    if (fv_idx_.count(var) == 0) {
                        vars_.push_back(var);
                        fv_idx_[var] = vars_.size() - 1;
                    }
                    vector<int> k(fv_idx_[var] + 1);
                    k[fv_idx_[var]] = 1;
                    tmp[k] = 1;
                }
                if (!operatorStk.empty() && operatorStk.top() == '*') {
                    multi(tmp, pStk.top());
                    operatorStk.pop();
                }
                continue;
            }
            // oprators
            if (exp[i] == '+') {
                operatorStk.push('+');
            } else if (exp[i] == '-') {
                operatorStk.push('-');
            } else if (exp[i] == '*') {
                operatorStk.push('*');
            } else if (exp[i] == '(') {
                operatorStk.push('(');
            } else if (exp[i] == ')') {
                Polys tmp;
                tmp[{}] = 0;
                while (operatorStk.top() != '(') {
                    calculate(tmp, pStk.top(), operatorStk.top());
                    operatorStk.pop();
                    pStk.pop();
                }
                operatorStk.pop();
                pStk.push(tmp);
            }
        }
        Polys ret;
        ret[{}] = 0;
        while (!pStk.empty()) {
            calculate(ret, pStk.top(), operatorStk.top());
            operatorStk.pop();
            pStk.pop();
        }
        return ret;
    }
    void calculate(Polys& x, Polys& y, char op) {
        switch (op) {
            case '+' :
                add(x, y);
                break;
            case '-' :
                minus(x, y);
                break;
            case '*' :
                multi(x, y);
                break;
        }
    }
    void add(Polys& x, Polys& y) {
        for (auto& p : y) {
            auto iter(x.find(p.first));
            if (iter == x.end()) {
                x.insert(p);
            } else {
                iter->second += p.second;
            }
        }
    }
    void minus(Polys& x, Polys& y) {
        for (auto& p : y) {
            auto iter(x.find(p.first));
            if (iter == x.end()) {
                x.insert(p);
            } else {
                iter->second -= p.second;
            }
        }
    }
    void multi(Polys& x, Polys& y) {
        Polys ret;
        for (auto& xx : x) {
            for (auto& yy : y) {
                int coef(xx.second * yy.second);
                vector<int> k(vars_.size());
                for (int i(0); i < xx.first.size(); ++i) { k[i] += xx.first[i]; }
                for (int i(0); i < yy.first.size(); ++i) { k[i] += yy.first[i]; }
                auto iter(ret.find(k));
                if (iter == ret.end()) {
                    ret[k] = coef;
                } else {
                    iter->second += coef;
                }
            }
        }
        swap(x, ret);
    }
    vector<string> getAnswer(const Polys& ps) {
        vector<string> ans;
        /*
        for (auto& p : ps) {
            if (p.second == 0) { continue; }
            string tmp(to_string(p.second));
            vector<string_view> fv;
            for (int i(0); i < p.first.size(); ++i) {
                while (p.first[i]-- > 0) { fv.push_back(vars_[i]); }
            }
            sort(fv.begin(), fv.end(), [](const string))
            for (auto& str : p.first) {
                if (str.empty()) { continue; }
                tmp += '*';
                tmp += str;
            }
            ans.emplace_back(move(tmp));
        }
        */
        return ans;
    }
private:
    vector<string_view> vars_;
    unordered_map<string_view, int> fv_idx_;
    unordered_map<string_view, int> known_;
};
// @lc code=end

