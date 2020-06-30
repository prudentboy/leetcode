/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        if (nums.size() == 1) return {to_string(nums[0])};

        int i(0), j(1);
        string tmp;
        while (i <= j && j < nums.size())
        {
            while (j < nums.size() && nums[j] == (long long int)nums[j - 1] + 1) ++j;
            tmp = (i + 1 == j) ? to_string(nums[i]) : (to_string(nums[i]).append("->").append(to_string(nums[j - 1])));
            ans.push_back(tmp);
            i = j;
            j = i + 1;
            if (i == nums.size() - 1) ans.push_back(to_string(nums[i]));
        }

        return ans;
    }
};

