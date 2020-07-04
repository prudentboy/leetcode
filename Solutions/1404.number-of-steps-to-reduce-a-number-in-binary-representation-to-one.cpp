/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
class Solution {
public:
    int numSteps(string s) {
        if (s.size() == 1) { return 0; }

        int ans(0);
        int n(s.size()), idx(0), carry(0);
        for (idx = n - 1; idx > 0; --idx) {
            s[idx] += carry;
            ++ans;
            if (s[idx] == '1') {
                ++ans;
                carry = 1;
            }
        }
        if (carry == 1) { ++ans; }
        return ans;
    }
};
// @lc code=end

