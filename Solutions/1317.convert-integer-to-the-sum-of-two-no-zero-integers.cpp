/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i(1); i < n; ++i) {
            if (containZero(i) || containZero(n - i)) { continue; }
            return {i, n - i};
        }
        return {1, n - 1};
    }
private:
    bool containZero(int n) {
        int digit(0);
        while (n > 0) {
            digit = n % 10;
            if (digit == 0) {return true; }
            n /= 10;
        }
        return false;
    }
};
// @lc code=end

