/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i(0), j(0);
        char c(0);
        while (i < s.size() && j < t.size())
        {
            c = s[i++];
            while (j < t.size() && t[j] != c) ++j;
            if (j >= t.size()) return false;
            ++j;
        }
        return (i == s.size());
    }
};

