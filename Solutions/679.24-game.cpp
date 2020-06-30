/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        for (double x : getABResult(nums[0], nums[1])) {
            if (judgePoint24(x, nums[2], nums[3])) { return true; }
        }
        for (double x : getABResult(nums[0], nums[2])) {
            if (judgePoint24(x, nums[1], nums[3])) { return true; }
        }
        for (double x : getABResult(nums[0], nums[3])) {
            if (judgePoint24(x, nums[2], nums[1])) { return true; }
        }
        for (double x : getABResult(nums[2], nums[1])) {
            if (judgePoint24(x, nums[0], nums[3])) { return true; }
        }
        for (double x : getABResult(nums[3], nums[1])) {
            if (judgePoint24(x, nums[2], nums[0])) { return true; }
        }
        for (double x : getABResult(nums[2], nums[3])) {
            if (judgePoint24(x, nums[0], nums[1])) { return true; }
        }
        return false;
    }
private:
    bool judgePoint24(double a, double b, double c) {
        for (double x : getABResult(a, b)) {
            if (judgePoint24(x, c)) { return true; }
        }
        for (double x : getABResult(a, c)) {
            if (judgePoint24(x, b)) { return true; }
        }
        for (double x : getABResult(c, b)) {
            if (judgePoint24(x, a)) { return true; }
        }
        return false;
    }
    bool judgePoint24(double a, double b) {
        if (abs(a + b - 24.0) < 1e-9) { return true; }
        if (abs(a - b - 24.0) < 1e-9) { return true; }
        if (abs(a * b - 24.0) < 1e-9) { return true; }
        if (abs(a / b - 24.0) < 1e-9) { return true; }
        if (abs(b - a - 24.0) < 1e-9) { return true; }
        if (abs(b / a - 24.0) < 1e-9) { return true; }
        return false;
    }
    vector<double> getABResult(double a, double b) {
        vector<double> ans({a + b, a - b, b - a, a * b});
        if (abs(a - 0.0) >= 1e-9) { ans.push_back(b / a); }
        if (abs(b - 0.0) >= 1e-9) { ans.push_back(a / b); }
        return ans;
    } 
};
// @lc code=end

