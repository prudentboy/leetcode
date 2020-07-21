/*
 * @lc app=leetcode id=1362 lang=cpp
 *
 * [1362] Closest Divisors
 */

// @lc code=start
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int mn(num);
        vector<int> ans({1, num + 1});
        for (int i(1); i <= sqrt(num + 2); ++i) {
            if ((num + 1) % i == 0) {
                if (abs(i - (num + 1) / i) < mn) {
                    mn = abs(i - (num + 1) / i);
                    ans[0] = i;
                    ans[1] = (num + 1) / i;
                }
            } else if ((num + 2) % i == 0) {
                if (abs(i - (num + 2) / i) < mn) {
                    mn = abs(i - (num + 2) / i);
                    ans[0] = i;
                    ans[1] = (num + 2) / i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

