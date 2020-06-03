/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string ans(address.size() + 6, ' ');
        for (int i = 0, j = 0; i < address.size(); ++i, ++j) {
            if (isdigit(address[i])) {
                ans[j] = address[i];
            } else {
                ans[j++] = '[';
                ans[j++] = address[i];
                ans[j] = ']';
            }
        }
        return ans;
    }
};
// @lc code=end

