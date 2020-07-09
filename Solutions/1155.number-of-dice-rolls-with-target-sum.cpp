/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> memo(d * 1000 + target + 1, -1);
        return numRollsToTarget(d, f, target, memo);
    }
private:
    int numRollsToTarget(int d, int f, int target, vector<int>& memo) {
        if (d == 0 && target == 0) { return 1; }
        if (d <= 0 || target <= 0) { return 0; }
        if (d > target || d * f < target) { return 0; }
        if (memo[d * 1000 + target] != -1) { return memo[d * 1000 + target]; }
        long long int num(0);
        for (int i(1); i <= f; ++i) {
            num += numRollsToTarget(d - 1, f, target - i, memo);
            num %= 1000000007;
        }
        //cout << d << ' ' << target << ' ' << num << endl;
        return memo[d * 1000 + target] = num;
    } 
};
// @lc code=end

