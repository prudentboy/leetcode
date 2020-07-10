/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        return reverseParentheses(s, 0, s.size());
    }
    string reverseParentheses(const string& s, int beg, int end) {
        //cout << beg << ' ' << end << endl;
        if (beg < 0 || end < 0 || beg > s.size() || end > s.size() || beg == end) { return ""; }

        string ans;
        int step(beg < end ? 1 : -1);
        for (int i(beg); i != end; i += step) {
            //cout << i << ' ' << s[i] << endl;
            if (isalpha(s[i])) {
                ans += s[i];
                continue;
            }
            char par(s[i]);
            int cnt(1), j(i + step);
            for (; j != end; j += step) {
                if (s[j] == par) {
                    ++cnt;
                } else if (s[j] == par + step) {
                    --cnt;
                }
                if (cnt == 0) { break;}
            }
            ans += reverseParentheses(s, j - step, i);
            //cout << ans << ' ' << i << ' ' << j << ' ' << step << endl;
            i = j;
        }
        cout << beg << ' ' << end << ' ' << ans << endl;
        return ans;
    }
};
// @lc code=end

