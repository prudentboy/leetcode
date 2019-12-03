/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        string s(std::move(to_string(N)));
        int i(0), j(s.size());
        for (i = j - 1; i > 0; --i)
        {
            if (s[i - 1] <= s[i]) continue;
            --s[i - 1];
            j = i;
        }
        for (i = j; i < s.size(); ++i) s[i] = '9';
        return stoi(s);
    }
};
// @lc code=end

