/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> v(40, 0);
        int mx(0);
        for (int i = 1; i <= n; ++i) {
            mx = max(mx, ++v[sumDigits(i)]);
        }
        int ans(0);
        for (int i(1); i < 40; ++i) {
            if (v[i] == mx) { ++ans; }
        }
        return ans;
    }
private:
    int sumDigits(int n) {
        int s(0);
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
};
// @lc code=end

