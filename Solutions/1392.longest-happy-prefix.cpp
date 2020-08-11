/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() < 2) { return ""; }
        string_view str(s);
        const int n(s.size());
        const int M = 1000000007;
        long pre(0), suf(0), base(1);
        int mx(0);
        for (int i(1); i < n; ++i) {
            suf += (str[n - i] - 'a') * base;
            pre *= 26;
            pre += str[i - 1] - 'a';
            base *= 26;
            suf %= M;
            pre %= M;
            base %= M;
            //cout << str.substr(n - i) << ',' << str.substr(0, i) << ':';
            //cout << suf << ' ' << pre << endl;
            if (pre == suf && str.substr(0, i) == str.substr(n - i)) { mx = i; }
        }
        return s.substr(0, mx);
    }
};
// @lc code=end

