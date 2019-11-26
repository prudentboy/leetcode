/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1(s1.size()), n2(s2.size());
        if (n1 > n2) return false;
        string mark1(26, '0'), mark2(26, '0');
        for (char c : s1) ++mark1[c - 'a'];
        int i(0);
        for (i = 0; i < n1; ++i) ++mark2[s2[i] - 'a'];
        if (mark1 == mark2) return true;
        for (i = n1; i < n2; ++i)
        {
            ++mark2[s2[i] - 'a'];
            --mark2[s2[i - n1] - 'a'];
            if (mark1 == mark2) return true;
        }
        return false;
    }
};
// @lc code=end

