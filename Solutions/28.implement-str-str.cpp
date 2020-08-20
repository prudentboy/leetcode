/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { return 0; }

        const int n(haystack.size()), m(needle.size());
        if (m > n) { return -1; }

        // bruce force
        /*
        string_view hs(haystack);
        for (int i(0); i + m <= n; ++i) {
            if (hs.substr(i, m) == needle) { return i; }
        }
        */
        
        // kmp
        vector<int> next(2, 0);
        for (int i(1), j(0); i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) { j = next[j]; }
            if (needle[i] == needle[j]) { ++j; }
            next.emplace_back(j);
        }
        //for (int i(0); i < next.size(); ++i) { cout << next[i] << ' '; }
        //cout << endl;
        for (int i(0), j(0); i < n; ++i) {
            while (j > 0 && needle[j] != haystack[i]) { j = next[j]; }
            if (needle[j] == haystack[i]) { ++j; }
            if (j == m) { return i - m + 1; }
        }

        return -1;
    }
};
// @lc code=end

