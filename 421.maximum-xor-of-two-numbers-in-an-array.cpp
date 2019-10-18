/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans(0), mask(0), tmp(0);

        unordered_set<int> s;
        for (int i(31); i >= 0; --i)
        {
            s.clear();
            mask |= (1 << i);
            for (int n : nums) s.insert(n & mask);
            tmp = ans | (1 << i);
            for (int n : s)
            {
                if (s.count(n ^ tmp) > 0)
                {
                    ans = tmp;
                    break;
                }
            }
            //cout << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

