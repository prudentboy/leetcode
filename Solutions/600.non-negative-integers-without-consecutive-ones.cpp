/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int num) {
        vector<int> fibo(32, 0);
        fibo[0] = 1, fibo[1] = 2;
        int i(0);
        for (i = 2; i < 32; ++i) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }

        int ans(0);
        int digit(31);
        bool preOne(false);
        while (digit >= 0) {
            if ((num & (1 << digit)) > 0) {
                ans += fibo[digit];
                //cout << digit << ' ' << ans << endl;
                if (preOne) return ans;
                preOne = true;
            } else { preOne = false; }
            --digit;
        }

        ++ans;
        return ans;
    }
};
// @lc code=end

