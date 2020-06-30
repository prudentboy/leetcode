/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string s(to_string(n));
        next_permutation(s.begin(), s.end());
        long long int ans(stoll(s));
        return (ans > INT_MAX || ans <= n) ? -1 : ans;
    }
};
// @lc code=end

