/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) { return false; }
        if (k == s.size()) { return true; }

        unordered_map<char, int> um;
        int odd(0), even(0);

        for (char c : s) {
            ++um[c];
        }

        for (auto& p : um) {
            if ((p.second & 1) == 1) {
                ++odd;
            }
        }

        return k >= max(1, odd);
    }
};
// @lc code=end

