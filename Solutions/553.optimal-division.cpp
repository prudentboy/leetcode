/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

// @lc code=start
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.empty()) return "";
        if (nums.size() == 1) return to_string(nums[0]);
        string ans(to_string(nums[0]));
        ans += '/';
        if (nums.size() == 2)
        {
            ans.append(to_string(nums[1]));
            return ans;
        }
        ans += '(';
        for (int i(1); i < nums.size(); ++i)
        {
            ans.append(to_string(nums[i]));
            ans += '/';
        }
        ans.pop_back();
        ans += ')';
        return ans;
    }
};
// @lc code=end