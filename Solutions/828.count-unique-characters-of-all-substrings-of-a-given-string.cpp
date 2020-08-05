/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        const int M = 1000000007;
        long ans(0), cur(0);
        vector<int> pre(26), prepre(26);
        for (int i(0); i < s.size(); ++i) {
            int idx(s[i] - 'A');
            cur += i + 1 + prepre[idx] - (pre[idx] << 1);
            ans += cur;
            ans %= M;
            prepre[idx] = pre[idx];
            pre[idx] = i + 1;
        }
        return ans;
    }
};
// @lc code=end

