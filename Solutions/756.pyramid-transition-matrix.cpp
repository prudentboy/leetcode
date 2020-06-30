/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> dict;
        for (const string& s : allowed) dict[s.substr(0, 2)].insert(s[2]);
        return helper(bottom, "", dict);
    }
private:
    bool helper(const string& bottom, string cur, unordered_map<string, unordered_set<char>>& dict) {
        if (bottom.size() <= 1) return true;
        if (cur.size() + 1 == bottom.size()) return helper(cur, "", dict);
        string tmp(bottom.substr(cur.size(), 2));
        if (dict.count(tmp) == 0) return false;
        for (auto it = dict[tmp].begin(); it != dict[tmp].end(); ++it) {
            cur += *it;
            if (helper(bottom, cur, dict)) return true;
            cur.pop_back();
        }
        return false;
    }
};
// @lc code=end

