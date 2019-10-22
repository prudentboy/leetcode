/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

// @lc code=start
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string ans;
        int cnt(0), carry(0), bit(0);
        while (N > 0 || carry > 0)
        {
            bit = (N & 1) + carry;
            ans.push_back((bit & 1) + '0');
            carry = (bit >> 1);
            if ((cnt++ & 1) == 1 && bit >= 1) carry = 1;
            N >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

