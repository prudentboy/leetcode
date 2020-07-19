/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() - k + 1 < (1 << k)) { return false; }
        unordered_set<string_view> ust;
        for (int i(0); i + k <= s.size(); ++i) { ust.insert(s.substr(i, k)); }
        return ust.size() == (1 << k);
    }
};
// @lc code=end

