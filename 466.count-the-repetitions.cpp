/*
 * @lc app=leetcode id=466 lang=cpp
 *
 * [466] Count The Repetitions
 */

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        if (s1.size() * n1 < s2.size() * n2) return 0;
        vector<bool> table(26, false);
        for (char c : s1) table[c - 'a'] = true;
        for (char c : s2) if (!table[c - 'a']) return 0;

        size_t i(0), j(0), k(0), l(0);
        size_t cnt(0);
        vector<int> cnts(n1 + 1, 0), indexs(cnts);
        for (k = 1; k <= n1; ++k)
        {
            for (i = 0; i < s1.size(); ++i)
            {
                if (s1[i] != s2[j]) continue;
                ++j;
                if (j == s2.size())
                {
                    ++cnt;
                    j = 0;
                }
            }
            cnts[k] = cnt;
            indexs[k] = j;
            for (l = 0; l < k; ++l)
            {
                if (indexs[l] == j)
                {
                    int patternCnt = (cnts[k] - cnts[l]) * ((n1 - l) / (k - l));
                    int remainCnt = cnts[l + (n1 - l) % (k - l)];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return cnts[n1] / n2;
    }
};
// @lc code=end

