/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        string ans, tmp;
        istringstream iss(s);
        while (iss >> tmp)
        {
            ans = ' ' + tmp + ans;
        }
        ans.erase(0, 1);

        return ans;
    }
};

