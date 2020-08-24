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
                Polys tmp;
                tmp[{}] = num;
                if (!operatorStk.empty() && operatorStk.top() == '*') {
                    multi(tmp, pStk.top());
                    operatorStk.pop();
                    pStk.pop();
                }
                pStk.push(tmp);
                continue;
            }
            // variable
            if (isalpha(exp[i])) {
                int beg(i), len(0);
                while (i < exp.size() && isalpha(exp[i])) {
                    ++i;
                    ++len;
                }
                --i;
                string_view var(exp.substr(beg, len));
                Polys tmp;
                if (known_.count(var) > 0) {
                    tmp[{}] = known_[var];
                } else {
                    if (fv_idx_.count(var) == 0) {
                        vars_.push_back(var);
                        fv_idx_[var] = vars_.size() - 1;
                    }
                    vector<int> k(20);
                    k[fv_idx_[var]] = 1;
                    tmp[k] = 1;
                }
                if (!operatorStk.empty() && operatorStk.top() == '*') {
                    multi(tmp, pStk.top());
                    operatorStk.pop();
                    pStk.pop();
                }
                pStk.push(tmp);
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
                operatorStk.push('+');
            } else if (exp[i] == ')') {
                Polys tmp;
                tmp[{}] = 0;
                //cout << pStk.size() << '|' << operatorStk.size() << endl;
                while (operatorStk.top() != '(') {
                    calculate(tmp, pStk.top(), operatorStk.top());
                    operatorStk.pop();
                    pStk.pop();
                }
                operatorStk.pop();
                if (!operatorStk.empty() && operatorStk.top() == '*') {
                    multi(tmp, pStk.top());
                    operatorStk.pop();
                    pStk.pop();
                }
                pStk.push(tmp);
                //cout << pStk.size() << '|' << operatorStk.size() << endl;
                //Print(tmp);
            }
            //cout << pStk.size() << '|' << operatorStk.size() << endl;
            //if (!pStk.empty()) { Print(pStk.top()); }
            //if (!operatorStk.empty()) { cout << operatorStk.top() << endl; }
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
                x[p.first] = -p.second;
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
                vector<int> k(20);
                int i(0);
                for (i = 0; i < xx.first.size(); ++i) { k[i] += xx.first[i]; }
                for (i = 0; i < yy.first.size(); ++i) { k[i] += yy.first[i]; }
                for (i = 0; i < k.size(); ++i) { if (k[i] != 0) { break; } }
                if (i == k.size()) {
                    ret[{}] += coef;
                    continue;
                }
                auto iter(ret.find(k));
                if (iter == ret.end()) {
                    ret[k] = coef;
                } else {
                    iter->second += coef;
                }
            }
        }
        /*
        Print(x);
        cout << "-------" << endl;
        Print(y);
        cout << "-------" << endl;
        Print(ret);
        */
        x = ret;
    }
    vector<string> getAnswer(const Polys& ps) {
        //Print(ps);
        vector<pair<vector<string_view>, int>> vec;
        for (auto& p : ps) {
            if (p.second == 0) { continue; }
            vector<string_view> fv;
            for (int i(0); i < p.first.size(); ++i) {
                int cnt(p.first[i]);
                while (cnt-- > 0) { fv.push_back(vars_[i]); }
            }
            sort(fv.begin(), fv.end());
            vec.push_back({fv, p.second});
        }
        sort(vec.rbegin(), vec.rend(), [](const pair<vector<string_view>, int>& left, const pair<vector<string_view>, int>& right){
            if (left.first.size() == right.first.size()) { return left.first > right.first; }
            return left.first.size() < right.first.size();
        });
        vector<string> ans;
        for (auto& p : vec) {
            string tmp(to_string(p.second));
            if (!p.first.empty()) {
                for (auto str : p.first) {
                    tmp += '*';
                    tmp += string(str);
                }
            }
            ans.emplace_back(move(tmp));
        }
        return ans;
    }
    void Print(const Polys& pol) {
        for (auto& p : pol) {
            for (int i(0); i < p.first.size(); ++i) { cout << vars_[i] << ' '; }
            cout << ':';
            cout << p.second << endl;
        }
    }
private:
    vector<string_view> vars_;
    unordered_map<string_view, int> fv_idx_;
    unordered_map<string_view, int> known_;
};
// @lc code=end

