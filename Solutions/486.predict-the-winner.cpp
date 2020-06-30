/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.empty()) return false;
        return PredictTheWinner(nums, 0, nums.size() - 1, 0, 0, 1);
    }
private:
    bool PredictTheWinner(const vector<int>& nums, int begin, int end, int sum1, int sum2, int player)
    {
        //cout << begin << ' ' << end << ' ' << sum1 << ' ' << sum2 << ' ' << player << endl;
        if (begin == end)
        {
            if (player == 1) sum1 += nums[begin];
            else sum2 += nums[begin];
            return sum1 >= sum2;
        }
        if (player == 1) return PredictTheWinner(nums, begin + 1, end, sum1 + nums[begin], sum2, 2) || PredictTheWinner(nums, begin, end - 1, sum1 + nums[end], sum2, 2);
        else return PredictTheWinner(nums, begin + 1, end, sum1, sum2 + nums[begin], 1) && PredictTheWinner(nums, begin, end - 1, sum1, sum2 + nums[end], 1);
    }
};
// @lc code=end

