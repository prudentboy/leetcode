/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
class Solution {
    using Poly = multiset<string>;
    using Polys = map<Poly, int, function<bool(const Poly&, const Poly&)>>;
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        auto cmp = [](const Poly& left, const Poly& right) -> bool {
            if (left.size() == right.size()) { return left < right; }
            return left.size() < right.size();
        };
        Polys ret(cmp);

        unordered_map<string_view, int> valUmp;
        const int m(evalvars.size());
        for (int i(0); i < m; ++i) { valUmp[evalvars[i]] = evalints[i]; }

        string_view exp(expression);
        stack<Polys> pStk;
        stack<char> opStk;
        for (int i(0); i < expression.size(); ++i) {
            // digit
            if (isdigit(exp[i])) {
                int num(exp[i++] - '0');
                while (i < expression.size() && isdigit(exp[i])) {
                    num *= 10;
                    num += exp[i++] - '0';
                }
                --i;
                if (num == 0) continue;
                pStk.push({"", num});
                continue;
            }
            // variable
            if (isalpha(expression[i])) {
                int beg(i), len(1);
                while (i < expression.size() && isalpha(exp[i])) {
                    ++i;
                    ++len;
                }
                --i;
                string_view ex(expression.substr(beg, len));
                pStk.push(valUmp.count(ex) > 0 ? {"", valUmp[ex]} : {ex, 1});
                continue;
            }

        }
        return getAnswer(ret);
    }
private:
    Polys add(Polys& x, Polys& y) {
        for (auto& p : y) {
            auto iter(x.find(p.first));
            if (iter == x.end()) {
                x.insert(p);
            } else {
                iter->second += p.second;
                if (iter->second == 0) { x.erase(iter); }
            }
        }
        return x;
    }
    Polys minus(Polys& x, Polys& y) {
        for (auto& p : y) {
            auto iter(x.find(p.first));
            if (iter == x.end()) {
                x.insert(p);
            } else {
                iter->second += p.second;
                if (iter->second == 0) { x.erase(iter); }
            }
        }
        return x;
    }
    Polys multiply(Polys& x, Polys& y) {
        Polys ret;
        for (auto& xx : x) {
            for (auto& yy : y) {
                int coef(xx.second * yy.second);
                Poly nxtPoly(xx.first);
                for (auto& s : yy.first) { nxtPoly.insert(s); }
                auto iter(ret.find(nxtPoly));
                if (iter == ret.end()) {
                    ret[nxtPoly] = coef;
                } else {
                    iter->second += coef;
                    if (iter->second == 0) { ret.erase(iter); }
                } 
            }
        }
        return ret;
    }
    vector<string> getAnswer(const Polys& ps) {
        vector<string> ans;
        for (auto& p : ps) {
            string tmp(to_string(p.second));
            for (auto& str : p.first) {
                if (str.empty()) { continue; }
                tmp += '*';
                tmp += str;
            }
            ans.emplace_back(move(tmp));
        }
        return ans;
    }
};
// @lc code=end

