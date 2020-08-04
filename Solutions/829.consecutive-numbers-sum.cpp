/*
 * @lc app=leetcode id=829 lang=cpp
 *
 * [829] Consecutive Numbers Sum
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int sum(0), ans(0);
        for (int i(1); sum < N; ++i) {
            sum += i;
            if ((N - sum) % i == 0) { ++ans; }
        }
        return ans;
    }
};
// @lc code=end

