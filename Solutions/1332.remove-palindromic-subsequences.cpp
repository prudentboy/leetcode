/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) { return 0; }
        if (isPalindrome(s)) { return 1; }
        return 2;
    }
private:
    bool isPalindrome(const string& s) {
        if (s.empty()) { return false; }
        int left(0), right(s.size() - 1);
        while (left < right) {
            if (s[left] != s[right]) { return false; }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

