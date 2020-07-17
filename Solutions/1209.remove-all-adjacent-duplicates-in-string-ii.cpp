/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) { return s; }

        string ns;
        int i(0), j(0), cnt(1), n(s.size());
        for (i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                cnt = 0;
                while (j < i) { ns += s[j++]; }
            }
            ++cnt;
            if (cnt == k) {
                j = i + 1;
            }
        }
        while (j < i) { ns += s[j++]; }

        if (ns == s) { return s; }
        return removeDuplicates(ns, k);
    }
};
// @lc code=end

