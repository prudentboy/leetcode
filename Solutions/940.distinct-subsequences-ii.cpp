/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string S) {
        const int M = 1000000007;
        vector<int> cnts(26);
        for (char c : S) {
            cnts[c - 'a'] = accumulate(cnts.begin(), cnts.end(), 1L) % M;
        }
        return accumulate(cnts.begin(), cnts.end(), 0L) % M;
    }
};
// @lc code=end

