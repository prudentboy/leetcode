/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int forward(0), backward(0);
        for (char c : S) {
            forward += (c - '0');
            backward = min(forward, backward + 1 + '0' - c);
        }
        return backward;
    }
};
// @lc code=end

