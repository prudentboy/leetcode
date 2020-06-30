/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> m;
        char l, r;
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                l = getGroup(m, eq[0]);
                r = getGroup(m, eq[3]);
                m[r] = l;
            }
        }
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                if (getGroup(m, eq[0]) == getGroup(m, eq[3])) { return false; }
            }
        }
        return true;
    }
private:
    char getGroup(unordered_map<char, char>& m, char c) {
        if (m.count(c) == 0) {
            m[c] = c;
            return c;
        }
        if (m[c] == c) { return c; }
        return getGroup(m, m[c]);
    }
};
// @lc code=end

