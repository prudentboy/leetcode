/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnts(26, 0);
        for (char c : s) { ++cnts[c - 'a']; }
        for (char c : t) { --cnts[c - 'a']; }
        int cnt(0);
        for (int n : cnts) { cnt += abs(n); }
        return cnt >> 1;
    }
};
// @lc code=end

