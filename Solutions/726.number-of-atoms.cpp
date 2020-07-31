/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string_view, int> atoms;
        countOfAtoms(formula, 1, atoms);

        string ans;
        vector<pair<string_view, int>> v(atoms.begin(), atoms.end());
        sort(v.begin(), v.end());
        for (auto& p : v) {
            ans += p.first;
            if (p.second > 1) { ans += to_string(p.second); }
        }
        return ans;
    }
private:
    void countOfAtoms(string_view formula, int coef, unordered_map<string_view, int>& atoms) {
        //cout << formula << ' ' << coef << endl;
        bool toRecord(false);
        int i(0), cnt(0), start(-1), end(-1);
        for (i = 0; i < formula.size(); ++i) {
            if (formula[i] == '(') {
                if (toRecord) {
                    atoms[formula.substr(start, end - start + 1)] += cnt == 0 ? coef : cnt * coef;
                    toRecord = false;
                }
                int idx(i + 1), num(1);
                for (; idx < formula.size(); ++idx) {
                    if (formula[idx] == '(') { ++num; }
                    else if (formula[idx] == ')') { --num; }
                    else {continue; }
                    if (num == 0) { break; }
                }
                int j(idx + 1), co(0);
                for (; j < formula.size(); ++j) {
                    if (formula[j] > '9' || formula[j] < '0') { break; }
                    co = co * 10 + formula[j] - '0';
                }
                if (co == 0) { ++co; }
                countOfAtoms(formula.substr(i + 1, idx - i - 1), co * coef, atoms);
                i = j - 1;
                continue;
            }
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                if (toRecord) { atoms[formula.substr(start, end - start + 1)] += cnt == 0 ? coef : cnt * coef; }
                start = end = i;
                cnt = 0;
                toRecord = true;
            } else if (formula[i] >= 'a' && formula[i] <= 'z') {
                end = i;
            } else if (formula[i] >= '0' && formula[i] <= '9') {
                cnt = cnt * 10 + formula[i] - '0';
            }
        }
        if (toRecord) { atoms[formula.substr(start, end - start + 1)] += cnt == 0 ? coef : cnt * coef; }
    }
};
// @lc code=end

