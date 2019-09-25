/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2) return s;

        int i(0), j(s.size() - 1);
        for (; j >= 0; --j) if (s[i] == s[j]) ++i;

        if (i == s.size()) return s;
        string app(s.substr(i));
        reverse(app.begin(), app.end());
        //cout << app << endl;

        return app.append(shortestPalindrome(s.substr(0, i))).append(s.substr(i));
    }
};

