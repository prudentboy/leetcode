/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */

// @lc code=start
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string> ret(helper(expression));
        vector<string> ans;
        for (auto& str : ret) { if (!str.empty()) { ans.push_back(str); } }
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    unordered_set<string> helper(string_view exp) {
        unordered_set<string> ret;
        if (exp.empty()) { return ret; }
        if (exp.find(',') == string::npos && exp.find('{') == string::npos) { return {string(exp)}; }

        string cur;
        for (int i(0); i < exp.size(); ++i) {
            if (exp[i] == ',') {
                if (!cur.empty()) {
                    if (ret.empty()) {
                        ret.insert(cur);
                    } else {
                        auto cpy(ret);
                        ret.clear();
                        for (auto& e : cpy) { ret.insert(e + cur); }
                    }
                    cur.clear();
                }
                auto ust(helper(exp.substr(i + 1, exp.size() - i)));
                for (auto& e : ust) { ret.insert(e); }
                return ret;
            }
            if (exp[i] >= 'a' && exp[i] <= 'z') {
                cur += exp[i];
            } else if (exp[i] == '{') {
                if (!cur.empty()) {
                    if (ret.empty()) {
                        ret.insert(cur);
                    } else {
                        auto cpy(ret);
                        ret.clear();
                        for (auto& e : cpy) { ret.insert(e + cur); }
                    }
                    cur.clear();
                }
                int cnt(1), j(i + 1);
                for (; j < exp.size(); ++j) {
                    if (exp[j] == '{') {
                        ++cnt;
                    } else if (exp[j] == '}') {
                        if (--cnt == 0) { break; }
                    }
                }
                auto ust(helper(exp.substr(i + 1, j - i - 1)));
                if (ret.empty()) {
                    ret = ust;
                } else {
                    auto cpy(ret);
                    ret.clear();
                    for (auto& e : cpy) {
                        for (auto& u : ust) { ret.insert(e + u); }
                    }
                }
                i = j;
            }
        }
        if (!cur.empty()) {
            auto cpy(ret);
            ret.clear();
            for (auto& e : cpy) { ret.insert(e + cur); }
        }
        return ret;
    }
};
// @lc code=end

