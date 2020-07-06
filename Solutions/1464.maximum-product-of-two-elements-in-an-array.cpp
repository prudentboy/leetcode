/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1(0), n2(0);
        for (int n : nums) {
            if (n > n1) {
                n2 = n1;
                n1 = n;
            } else if (n > n2) {
                n2 = n;
            }
        }
        return (n1 - 1) * (n2 - 1);
    }
};
// @lc code=end

