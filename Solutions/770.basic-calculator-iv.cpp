/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        typedef multiset<string> Poly;
        typedef map<Poly, int, [](const Poly& left, const Poly& right) {
            if (left.size() == right.size()) { return left < right; }
            return left.size() < right.size();
        }> Polys;

        unordered_map<string_view, int> valUmp;
        const int m(evalvars.size());
        for (int i(0); i < m; ++i) { valUmp[evalvars[i]] = evalints[i]; }

        Expression exp(Expression::convertFromStr(expression, 0, expreesion.size() - 1, valUmp));
        return exp.getExpressionVec();
    }
};
// @lc code=end

