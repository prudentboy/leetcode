/*
 * @lc app=leetcode id=906 lang=cpp
 *
 * [906] Super Palindromes
 */

// @lc code=start
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long long int lInt(stoll(L)), rInt(stoll(R));

        int ans(0);
        if (lInt <= 9 && rInt >= 9) { ++ans; }
        if (lInt <= 4 && rInt >= 4) { ++ans; }
        if (lInt <= 1 && rInt >= 1) { ++ans; }

        string half, rev, base, square;
        long long int num(0);
        for (int i(1); i < 10000; ++i) {
            rev.assign(move(to_string(i)));
            half.assign(rev);
            reverse(rev.begin(), rev.end());
            base.assign(move(half + rev));
            num = stoll(base);
            num *= num;
            if (num > rInt) { break; }
            if (num >= lInt && isPalindrome(to_string(num))) { ++ans; }

            for (char j('0'); j <= '9'; ++j) {
                base.assign(move(half + j + rev));
                num = stoll(base);
                num *= num;
                if (num > rInt) { break; }
                if (num < lInt) { continue; }
                if (isPalindrome(to_string(num))) { ++ans; }
            }
        }

        return ans;
    }
private:
    bool isPalindrome(const string& s) {
        if (s.empty()) { return false; }

        int l(0), r(s.size() - 1);
        while (l < r) {
            if (s[l++] != s[r--]) { return false; }
        }
        return true;
    }
};
// @lc code=end

