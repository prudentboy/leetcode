/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        //cout << n << endl;
        if (n == 1) return 0;
        if (n < 6) return n;
        int i(0), ans(INT_MAX);
        for (int i(sqrt(n)); i > 1; --i)
        {
            if (n % i == 0)
            {
                ans = min(ans, minSteps(i) + n / i);
                ans = min(ans, minSteps(n / i) + i);
            }
        }
        return min(ans, n);
    }
};
// @lc code=end

