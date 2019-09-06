/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        string ans;
        ans.reserve(s.length());
        int i, j(s.size() - 1);

        while (i >= 0 and j >= 0)
        {
            while (j >= 0 && s[j] == ' ') --j;
            if (j < 0) break;
            i = j;
            while (i >= 0 && s[i] != ' ') --i;
            ans.append(s.substr(i + 1, j - i));
            ans.append(" ");
            j = i;
        }
        if (ans.back() == ' ') ans.pop_back();

        return ans;
    }
};

