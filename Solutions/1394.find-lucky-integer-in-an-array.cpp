/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int mn(INT_MAX), mx(INT_MIN);
        for (int n : arr) {
            mn = min(mn, n);
            mx = max(mx, n);
        }
        vector<int> count(mx - mn + 1, 0);
        for (int n : arr) {
            ++count[n - mn];
        }
        for (int i = count.size() - 1; i >= 0; --i) {
            if (count[i] == i + mn) { return count[i]; }
        }
        return -1;
    }
};
// @lc code=end

