/*
 * @lc app=leetcode id=1433 lang=cpp
 *
 * [1433] Check If a String Can Break Another String
 */

// @lc code=start
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> cnt1(26), cnt2(26);
        for (char c : s1) { ++cnt1[c - 'a']; }
        for (char c : s2) { ++cnt2[c - 'a']; }

        bool bigger(true), smaller(true);
        int cum1(0), cum2(0);
        for (int i(0); i < 26; ++i) {
            cum1 += cnt1[i];
            cum2 += cnt2[i];
            if (!bigger && !smaller) { return false; }
            if (bigger) { bigger = bigger && cum1 <= cum2; }
            if (smaller) { smaller = smaller && cum1 >= cum2; }
        }

        return bigger || smaller;
    }
};
// @lc code=end

